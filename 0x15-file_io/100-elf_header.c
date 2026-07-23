/*
 * elf_header.c - Display the information contained in the ELF header
 * at the start of an ELF file.
 *
 * Usage:
 *     ./elf_header <path-to-elf-file>
 *
 * Uses the standard <elf.h> definitions (available on Linux) for the
 * ELF header layout, and handles both 32-bit and 64-bit files.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>

/* ------------------------------------------------------------------- */
/* Lookup helpers: turn raw numeric fields into readable strings       */
/* ------------------------------------------------------------------- */

static const char *class_str(unsigned char c)
{
    switch (c) {
        case ELFCLASSNONE: return "ELFCLASSNONE (invalid)";
        case ELFCLASS32:   return "ELFCLASS32 (32-bit)";
        case ELFCLASS64:   return "ELFCLASS64 (64-bit)";
        default:           return "Unknown";
    }
}

static const char *data_str(unsigned char d)
{
    switch (d) {
        case ELFDATANONE: return "ELFDATANONE (invalid)";
        case ELFDATA2LSB: return "ELFDATA2LSB (little endian)";
        case ELFDATA2MSB: return "ELFDATA2MSB (big endian)";
        default:          return "Unknown";
    }
}

static const char *osabi_str(unsigned char abi)
{
    switch (abi) {
        case ELFOSABI_SYSV:    return "System V";
        case ELFOSABI_HPUX:    return "HP-UX";
        case ELFOSABI_NETBSD:  return "NetBSD";
        case ELFOSABI_LINUX:   return "Linux";
        case ELFOSABI_SOLARIS: return "Solaris";
        case ELFOSABI_AIX:     return "AIX";
        case ELFOSABI_IRIX:    return "IRIX";
        case ELFOSABI_FREEBSD: return "FreeBSD";
        case ELFOSABI_TRU64:   return "Tru64";
        case ELFOSABI_OPENBSD: return "OpenBSD";
        case ELFOSABI_ARM:     return "ARM";
        case 255:              return "Standalone (embedded)";
        default:               return "Unknown";
    }
}

static const char *type_str(uint16_t t)
{
    switch (t) {
        case ET_NONE: return "ET_NONE (no file type)";
        case ET_REL:  return "ET_REL (relocatable file)";
        case ET_EXEC: return "ET_EXEC (executable file)";
        case ET_DYN:  return "ET_DYN (shared object/PIE)";
        case ET_CORE: return "ET_CORE (core file)";
        default:      return "Unknown";
    }
}

static const char *machine_str(uint16_t m)
{
    switch (m) {
        case EM_NONE:    return "None";
        case EM_SPARC:   return "SPARC";
        case EM_386:     return "x86";
        case EM_MIPS:    return "MIPS";
        case EM_PPC:     return "PowerPC";
        case EM_ARM:     return "ARM";
        case EM_X86_64:  return "x86-64";
        case EM_AARCH64: return "AArch64";
#ifdef EM_RISCV
        case EM_RISCV:   return "RISC-V";
#endif
        default:         return "Unknown";
    }
}

/* ------------------------------------------------------------------- */
/* Printing routines, one for 32-bit headers and one for 64-bit        */
/* ------------------------------------------------------------------- */

static void print_ident(const unsigned char *e_ident)
{
    printf("  Class:                             %s\n",
           class_str(e_ident[EI_CLASS]));
    printf("  Data:                              %s\n",
           data_str(e_ident[EI_DATA]));
    printf("  Version (e_ident):                 %d\n",
           e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n",
           osabi_str(e_ident[EI_OSABI]));
    printf("  ABI Version:                       %d\n",
           e_ident[EI_ABIVERSION]);
}

static void print_header32(const Elf32_Ehdr *eh)
{
    print_ident(eh->e_ident);
    printf("  Type:                              %u (%s)\n",
           eh->e_type, type_str(eh->e_type));
    printf("  Machine:                           %u (%s)\n",
           eh->e_machine, machine_str(eh->e_machine));
    printf("  Version (e_version):               0x%x\n", eh->e_version);
    printf("  Entry point address:               0x%08x\n", eh->e_entry);
    printf("  Start of program headers:          %u (bytes into file)\n",
           eh->e_phoff);
    printf("  Start of section headers:          %u (bytes into file)\n",
           eh->e_shoff);
    printf("  Flags:                             0x%x\n", eh->e_flags);
    printf("  Size of this header:               %u bytes\n", eh->e_ehsize);
    printf("  Size of program headers:           %u bytes\n", eh->e_phentsize);
    printf("  Number of program headers:         %u\n", eh->e_phnum);
    printf("  Size of section headers:           %u bytes\n", eh->e_shentsize);
    printf("  Number of section headers:         %u\n", eh->e_shnum);
    printf("  Section header string table index: %u\n", eh->e_shstrndx);
}

static void print_header64(const Elf64_Ehdr *eh)
{
    print_ident(eh->e_ident);
    printf("  Type:                              %u (%s)\n",
           eh->e_type, type_str(eh->e_type));
    printf("  Machine:                           %u (%s)\n",
           eh->e_machine, machine_str(eh->e_machine));
    printf("  Version (e_version):               0x%x\n", eh->e_version);
    printf("  Entry point address:               0x%016lx\n",
           (unsigned long) eh->e_entry);
    printf("  Start of program headers:          %lu (bytes into file)\n",
           (unsigned long) eh->e_phoff);
    printf("  Start of section headers:          %lu (bytes into file)\n",
           (unsigned long) eh->e_shoff);
    printf("  Flags:                             0x%x\n", eh->e_flags);
    printf("  Size of this header:               %u bytes\n", eh->e_ehsize);
    printf("  Size of program headers:           %u bytes\n", eh->e_phentsize);
    printf("  Number of program headers:         %u\n", eh->e_phnum);
    printf("  Size of section headers:           %u bytes\n", eh->e_shentsize);
    printf("  Number of section headers:         %u\n", eh->e_shnum);
    printf("  Section header string table index: %u\n", eh->e_shstrndx);
}

/* ------------------------------------------------------------------- */
/* Main                                                                 */
/* ------------------------------------------------------------------- */

int main(int argc, char *argv[])
{
    const char *path;
    FILE *fp;
    unsigned char e_ident[EI_NIDENT];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path-to-elf-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    path = argv[1];
    fp = fopen(path, "rb");
    if (!fp) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    if (fread(e_ident, 1, EI_NIDENT, fp) != EI_NIDENT) {
        fprintf(stderr, "Error: file is too small to contain a valid ELF header\n");
        fclose(fp);
        return EXIT_FAILURE;
    }

    if (memcmp(e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Error: not an ELF file (bad magic bytes)\n");
        fclose(fp);
        return EXIT_FAILURE;
    }

    printf("ELF Header for: %s\n", path);
    printf("------------------------------------------------------------\n");

    /* Rewind and read the full header now that we know the class */
    rewind(fp);

    if (e_ident[EI_CLASS] == ELFCLASS64) {
        Elf64_Ehdr eh;
        if (fread(&eh, 1, sizeof(eh), fp) != sizeof(eh)) {
            fprintf(stderr, "Error: file is too small to contain a complete 64-bit ELF header\n");
            fclose(fp);
            return EXIT_FAILURE;
        }
        print_header64(&eh);
    } else if (e_ident[EI_CLASS] == ELFCLASS32) {
        Elf32_Ehdr eh;
        if (fread(&eh, 1, sizeof(eh), fp) != sizeof(eh)) {
            fprintf(stderr, "Error: file is too small to contain a complete 32-bit ELF header\n");
            fclose(fp);
            return EXIT_FAILURE;
        }
        print_header32(&eh);
    } else {
        fprintf(stderr, "Error: unknown ELF class byte: %d\n", e_ident[EI_CLASS]);
        fclose(fp);
        return EXIT_FAILURE;
    }

    fclose(fp);
    return EXIT_SUCCESS;
}

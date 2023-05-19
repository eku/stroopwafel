#ifndef DYNAMIC_H
#define DYNAMIC_H

#include <elf.h>
#include <stddef.h>
#include "types.h"

#define LINKABLE __attribute__ ((weak))
#define MAGIC_DONE (0x444F4E45)
#define MAGIC_ELF (0x7F454C46)

LINKABLE void __wafel_dynamic(uintptr_t base, const Elf32_Dyn* dyn);
LINKABLE uintptr_t ios_elf_vaddr_to_paddr(uintptr_t addr);
LINKABLE Elf32_Phdr* ios_elf_add_phdr(uintptr_t addr);
LINKABLE void ios_elf_print_map();

LINKABLE uintptr_t wafel_plugin_max_addr(uintptr_t base);
LINKABLE uintptr_t wafel_plugin_next(uintptr_t base);
LINKABLE uintptr_t wafel_get_symbol_addr(uintptr_t base, const char* name);
LINKABLE void wafel_register_plugin(uintptr_t base);
LINKABLE uintptr_t wafel_find_symbol(const char* name);
LINKABLE uintptr_t wafel_find_symbol_multiple(const char* name, u32 skip);
LINKABLE uintptr_t wafel_get_plugin_base_by_idx(u32 idx);
LINKABLE void wafel_link_plugin(uintptr_t base);

extern uintptr_t wafel_plugin_base_addr;

#define MCP_ALTBASE_ADDR(_addr) (((u32)_addr) - wafel_plugin_base_addr + MCP_ALT_BASE)
#define FS_ALTBASE_ADDR(_addr) (((u32)_addr) - wafel_plugin_base_addr + FS_ALT_BASE)

#define RAMDISK_END (0x28000000)
#define CARVEOUT_SZ (RAMDISK_END - wafel_plugin_base_addr)

#endif // DYNAMIC_H
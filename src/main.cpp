#include "main_window.h"

#pragma region Blargg Tests
/*
CPU Instructions
carts/blargg/cpu_instrs/cpu_instrs.gb                        PASSED
carts/blargg/cpu_instrs/individual/01-special.gb             PASSED
carts/blargg/cpu_instrs/individual/02-interrupts.gb          PASSED
carts/blargg/cpu_instrs/individual/03-op sp,hl.gb            PASSED
carts/blargg/cpu_instrs/individual/04-op r,imm.gb            PASSED
carts/blargg/cpu_instrs/individual/05-op rp.gb               PASSED
carts/blargg/cpu_instrs/individual/06-ld r,r.gb              PASSED
carts/blargg/cpu_instrs/individual/07-jr,jp,call,ret,rst.gb  PASSED
carts/blargg/cpu_instrs/individual/08-misc instrs.gb         PASSED
carts/blargg/cpu_instrs/individual/09-op r,r.gb              PASSED
carts/blargg/cpu_instrs/individual/10-bit ops.gb             PASSED
carts/blargg/cpu_instrs/individual/11-op a,(hl).gb           PASSED

DMG Sound (DMG)
carts/blargg/dmg_sound/dmg_sound.gb
carts/blargg/dmg_sound/rom_singles/01-registers.gb

Instruction Timing
carts/blargg/instr_timing/instr_timing.gb                    PASSED

Interrupt Time (CGB)
carts/blargg/interrupt_time/interrupt_time.gb                NOT SUPPORTED

Memory Timing
carts/blargg/mem_timing/mem_timing.gb                        PASSED
carts/blargg/mem_timing/individual/01-read_timing.gb         PASSED
carts/blargg/mem_timing/individual/02-write_timing.gb        PASSED
carts/blargg/mem_timing/individual/03-modify_timing.gb       PASSED

Memory Timing 2
carts/blargg/mem_timing-2/mem_timing.gb                      PASSED
carts/blargg/mem_timing-2/individual/01-read_timing.gb       PASSED
carts/blargg/mem_timing-2/individual/02-write_timing.gb      PASSED
carts/blargg/mem_timing-2/individual/03-modify_timing.gb     PASSED

Halt Bug
carts/blargg/halt_bug.gb                                     PASSED
*/

#pragma endregion

#pragma region Mealybug Tearoom Tests

/*
carts/dmg-acid2/dmg-acid2.gb
carts/mealybug-tearoom/m2_win_en_toggle.gb
*/

#pragma endregion

#pragma region Mooneye Tests

/*
Acceptance
carts/mooneye/acceptance/bits/mem_oam.gb                     PASSED
carts/mooneye/acceptance/bits/reg_f.gb                       PASSED
carts/mooneye/acceptance/bits/unused_hwio-GS.gb              PASSED
carts/mooneye/acceptance/instr/daa.gb                        PASSED
carts/mooneye/acceptance/interrupts/ie_push.gb
carts/mooneye/acceptance/oam_dma/basic.gb                    PASSED
carts/mooneye/acceptance/oam_dma/reg_read.gb                 PASSED
carts/mooneye/acceptance/oam_dma/sources-GS.gb               PASSED
carts/mooneye/acceptance/ppu/hblank_ly_scx_timing-GS.gb
carts/mooneye/acceptance/ppu/intr_1_2_timing-GS.gb           PASSED
carts/mooneye/acceptance/ppu/intr_2_0_timing.gb              PASSED
carts/mooneye/acceptance/ppu/intr_2_mode0_timing.gb
carts/mooneye/acceptance/ppu/intr_2_mode0_timing_sprites.gb
carts/mooneye/acceptance/ppu/intr_2_mode3_timing.gb
carts/mooneye/acceptance/ppu/intr_2_oam_ok_timing.gb
carts/mooneye/acceptance/ppu/lcdon_timing-GS.gb
carts/mooneye/acceptance/ppu/lcdon_write_timing-GS.gb
carts/mooneye/acceptance/ppu/stat_irq_blocking.gb
carts/mooneye/acceptance/ppu/stat_lyc_onoff.gb
carts/mooneye/acceptance/ppu/vblank_stat_intr-GS.gb          PASSED
carts/mooneye/acceptance/serial/boot_sclk_align-dmgABCmgb.gb
carts/mooneye/acceptance/timer/div_write.gb                  PASSED
carts/mooneye/acceptance/timer/rapid_toggle.gb               PASSED
carts/mooneye/acceptance/timer/tim00.gb                      PASSED
carts/mooneye/acceptance/timer/tim00_div_trigger.gb          PASSED
carts/mooneye/acceptance/timer/tim01.gb                      PASSED
carts/mooneye/acceptance/timer/tim01_div_trigger.gb          PASSED
carts/mooneye/acceptance/timer/tim10.gb                      PASSED
carts/mooneye/acceptance/timer/tim10_div_trigger.gb          PASSED
carts/mooneye/acceptance/timer/tim11.gb                      PASSED
carts/mooneye/acceptance/timer/tim11_div_trigger.gb          PASSED
carts/mooneye/acceptance/timer/tima_reload.gb                PASSED
carts/mooneye/acceptance/timer/tima_write_reloading.gb       PASSED
carts/mooneye/acceptance/timer/tma_write_reloading.gb        PASSED
carts/mooneye/acceptance/add_sp_e_timing.gb                  PASSED
carts/mooneye/acceptance/boot_div-dmgABCmgb.gb               PASSED
carts/mooneye/acceptance/boot_hwio-dmgABCmgb.gb
carts/mooneye/acceptance/boot_regs-dmgABC.gb                 PASSED
carts/mooneye/acceptance/call_cc_timing.gb                   PASSED
carts/mooneye/acceptance/call_cc_timing2.gb
carts/mooneye/acceptance/call_timing.gb                      PASSED
carts/mooneye/acceptance/call_timing2.gb
carts/mooneye/acceptance/di_timing-GS.gb                     PASSED
carts/mooneye/acceptance/div_timing.gb                       PASSED
carts/mooneye/acceptance/ei_sequence.gb                      PASSED
carts/mooneye/acceptance/ei_timing.gb                        PASSED
carts/mooneye/acceptance/halt_ime0_ei.gb                     PASSED
carts/mooneye/acceptance/halt_ime0_nointr_timing.gb          PASSED
carts/mooneye/acceptance/halt_ime1_timing.gb                 PASSED
carts/mooneye/acceptance/halt_ime1_timing2-GS.gb             PASSED
carts/mooneye/acceptance/if_ie_registers.gb                  PASSED
carts/mooneye/acceptance/intr_timing.gb                      PASSED
carts/mooneye/acceptance/jp_cc_timing.gb                     PASSED
carts/mooneye/acceptance/jp_timing.gb                        PASSED
carts/mooneye/acceptance/ld_hl_sp_e_timing.gb                PASSED
carts/mooneye/acceptance/oam_dma_restart.gb                  PASSED
carts/mooneye/acceptance/oam_dma_start.gb                    PASSED
carts/mooneye/acceptance/oam_dma_timing.gb                   PASSED
carts/mooneye/acceptance/pop_timing.gb                       PASSED
carts/mooneye/acceptance/push_timing.gb
carts/mooneye/acceptance/rapid_di_ei.gb                      PASSED
carts/mooneye/acceptance/ret_cc_timing.gb                    PASSED
carts/mooneye/acceptance/ret_timing.gb                       PASSED
carts/mooneye/acceptance/reti_intr_timing.gb                 PASSED
carts/mooneye/acceptance/reti_timing.gb                      PASSED
carts/mooneye/acceptance/rst_timing.gb

Emulator Only
carts/mooneye/emulator-only/mbc1/bits_bank1.gb               PASSED
carts/mooneye/emulator-only/mbc1/bits_bank2.gb               PASSED
carts/mooneye/emulator-only/mbc1/bits_mode.gb                PASSED
carts/mooneye/emulator-only/mbc1/bits_ramg.gb                PASSED
carts/mooneye/emulator-only/mbc1/ram_256kb.gb                PASSED
carts/mooneye/emulator-only/mbc1/ram_64kb.gb                 PASSED
carts/mooneye/emulator-only/mbc1/rom_16Mb.gb                 PASSED
carts/mooneye/emulator-only/mbc1/rom_1Mb.gb                  PASSED
carts/mooneye/emulator-only/mbc1/rom_2Mb.gb                  PASSED
carts/mooneye/emulator-only/mbc1/rom_4Mb.gb                  PASSED
carts/mooneye/emulator-only/mbc1/rom_512kb.gb                PASSED
carts/mooneye/emulator-only/mbc1/rom_8Mb.gb                  PASSED
carts/mooneye/emulator-only/mbc2/bits_ramg.gb                PASSED
carts/mooneye/emulator-only/mbc2/bits_romb.gb                PASSED
carts/mooneye/emulator-only/mbc2/bits_unused.gb              PASSED
carts/mooneye/emulator-only/mbc2/ram.gb                      PASSED
carts/mooneye/emulator-only/mbc2/rom_1Mb.gb                  PASSED
carts/mooneye/emulator-only/mbc2/rom_2Mb.gb                  PASSED
carts/mooneye/emulator-only/mbc2/rom_512kb.gb                PASSED
carts/mooneye/emulator-only/mbc5/rom_16Mb.gb                 PASSED
carts/mooneye/emulator-only/mbc5/rom_1Mb.gb                  PASSED
carts/mooneye/emulator-only/mbc5/rom_2Mb.gb                  PASSED
carts/mooneye/emulator-only/mbc5/rom_32Mb.gb                 PASSED
carts/mooneye/emulator-only/mbc5/rom_4Mb.gb                  PASSED
carts/mooneye/emulator-only/mbc5/rom_512kb.gb                PASSED
carts/mooneye/emulator-only/mbc5/rom_64Mb.gb                 PASSED
carts/mooneye/emulator-only/mbc5/rom_8Mb.gb                  PASSED
*/

#pragma endregion

// Failing 16
// Passing 99

// carts/Donkey Kong Land (U) [S][!].gb
// carts/Final_Fantasy_Adventure_(U)_[!].gb
// carts/Legend of Zelda, The - Link's Awakening.gbc
// carts/Tetris (World) (Rev A).gb
// carts/Super Mario Land.gb
// carts/Kirby's Dream Land (USA, Europe).gb
// carts/Pokemon Green (U) [p1][!].gb

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    MainWindow mainWindow;
    mainWindow.setupUI();
    mainWindow.show();

    //TilesetMap tilesetMap(&gameboy);
    //tilesetMap.show();
    //
    //BackgroundMap backgroundMap(&gameboy);
    //backgroundMap.show();
    //
    //EmulationDisplay display(&gameboy);
    //display.show();

    return application.exec();
}

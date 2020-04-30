#include "gameboy.h"

#include <cstdio>
#include <ctime>
#include <iostream>

namespace trtle {
    extern "C" {
#define TRTLE_LOGGING_VERBOSE
#include <trtle/trtle.h>
    }
}

size_t const GameBoy::TilesetDataLength = GAMEBOY_TILESET_WIDTH * GAMEBOY_TILESET_HEIGHT;
size_t const GameBoy::TilesetWidthInPixels = GAMEBOY_TILESET_WIDTH;
size_t const GameBoy::TilesetHeightInPixels = GAMEBOY_TILESET_HEIGHT;

size_t const GameBoy::BackgroundDataLength = GAMEBOY_BACKGROUND_WIDTH * GAMEBOY_BACKGROUND_HEIGHT;
size_t const GameBoy::BackgroundWidthInPixels = GAMEBOY_BACKGROUND_WIDTH;
size_t const GameBoy::BackgroundHeightInPixels = GAMEBOY_BACKGROUND_HEIGHT;

size_t const GameBoy::DisplayDataLength = GAMEBOY_DISPLAY_WIDTH * GAMEBOY_DISPLAY_HEIGHT;
size_t const GameBoy::DisplayWidthInPixels = GAMEBOY_DISPLAY_WIDTH;
size_t const GameBoy::DisplayHeightInPixels = GAMEBOY_DISPLAY_HEIGHT;

GameBoy::GameBoy() : gameboy(trtle::gameboy_create()) {
    srand(time(NULL));
}

GameBoy::~GameBoy() {
    trtle::gameboy_delete(gameboy);
}

void GameBoy::insertCartridge(std::string const path) {
    trtle::Cartridge** cart = new trtle::Cartridge * ();
    int error = trtle::cartridge_from_file(cart, path.c_str());
    if (error) {
        std::cout << "Error loading cartridge: " << error << '\n';
        return;
    }
    if (*cart != NULL) trtle::gameboy_set_cartridge(gameboy, *cart);
    delete cart;
}

bool GameBoy::cartridgeInserted() {
    return gameboy->cartridge != nullptr;
}

void GameBoy::initialize(bool skipBootrom) {
    trtle::gameboy_initialize(gameboy, skipBootrom);
}

void GameBoy::updateToVBlank(bool a, bool b, bool start, bool select, bool up, bool down, bool left, bool right) {
    trtle::GameBoyInput input;
    input.a = a;
    input.b = b;
    input.start = start;
    input.select = select;
    input.up = up;
    input.down = down;
    input.left = left;
    input.right = right;

    trtle::gameboy_update_to_vblank(gameboy, input);
}

size_t GameBoy::getTilesetData(uint8_t tileset[], size_t length) {
    return gameboy_get_tileset_data(gameboy, tileset, length);
}

size_t GameBoy::getBackgroundData(uint8_t background[], size_t length) {
    return gameboy_get_background_data(gameboy, background, length);
}

size_t GameBoy::getDisplayData(uint8_t display[], size_t length) {
    return gameboy_get_display_data(gameboy, display, length);
}

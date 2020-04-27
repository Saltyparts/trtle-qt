#ifndef TRTLE_QT_GAMEBOY_HPP
#define TRTLE_QT_GAMEBOY_HPP
#include <cstdint>
#include <string>

namespace trtle {
    struct GameBoy;
    struct GameBoyInput;
}

class GameBoy {
public:
    static size_t const GameBoy::TilesetDataLength;
    static size_t const GameBoy::TilesetWidthInPixels;
    static size_t const GameBoy::TilesetHeightInPixels;

    static size_t const GameBoy::BackgroundDataLength;
    static size_t const GameBoy::BackgroundWidthInPixels;
    static size_t const GameBoy::BackgroundHeightInPixels;

    static size_t const GameBoy::DisplayDataLength;
    static size_t const GameBoy::DisplayWidthInPixels;
    static size_t const GameBoy::DisplayHeightInPixels;

    GameBoy();
    ~GameBoy();

    void insertCartridge(std::string const path);
    void initialize(bool skipBootrom);
    void updateToVBlank(bool a, bool b, bool start, bool select, bool up, bool down, bool left, bool right);
    size_t getTilesetData(uint8_t tileset[], size_t length);
    size_t getBackgroundData(uint8_t background[], size_t length);
    size_t getDisplayData(uint8_t display[], size_t length);

private:
    trtle::GameBoy * const gameboy;
};

#endif /* !TRTLE_QT_GAMEBOY_HPP */

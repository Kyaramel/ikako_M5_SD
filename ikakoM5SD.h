/**
 * @file ikakoM5SD.h
 * @author いかこう (kotakota925ika@gmail.com)
 * @brief sdカード関係のプログラムをまとめただけ
 * @version 0.1
 * @date 2024-04-06
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef IKAKO_M5SD_LIB
#define IKAKO_M5SD_LIB

#include <Arduino.h>
#include <FS.h>
#include <SD.h>
#include <SPI.h>

class ikakoM5SD
{
public:
    /**
     * @brief コンストラクタ
     *
     * @param fs
     */
    ikakoM5SD(fs::SDFS *fs);

    /**
     * @brief セットアップ
     *
     */
    void setup();

    /**
     * @brief ディレクトリの作成
     *
     * @param path
     */
    bool create_dir(char *path);

    /**
     * @brief ディレクトリの削除
     *
     * @param path
     */
    bool remove_dir(char *path);

    /**
     * @brief ファイル読み込み
     *
     * @param psth
     * @param buffer ファイルの内容を入れる変数
     */
    bool read(char *path, uint8_t buffer);
    bool read_bytes(char *path, char *buffer, size_t size);
    bool read_bytes_until(char *path, uint8_t *buffer, size_t size, char terminator);
    bool read_string(char *path, char *buffer, size_t size);
    bool read_string_until(char *path, char *buffer, char terminator);

    /**
     * @brief ファイル書き込み
     *
     * @param path
     * @param message
     */
    bool write_file(char *path, char *message);

    /**
     * @brief ファイルに追記
     *
     * @param path
     * @param message
     */
    bool append_file(char *path, char *message);

    /**
     * @brief ファイルの名前を変える
     *
     * @param path1
     * @param path2
     */
    bool rename_file(char *path1, char *path2);

    /**
     * @brief ファイルの削除
     *
     * @param path
     */
    bool delete_file(char *path);

    /**
     * @brief カードタイプの確認
     *
     * @return int
     */
    int get_card_type();

    /**
     * @brief カードサイズの確認
     *
     * @return int
     */
    int get_card_size();

private:
    fs::SDFS *my_sd;
    uint8_t card_type;
    uint64_t card_size;
};

#endif
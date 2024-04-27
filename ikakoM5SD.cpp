#include "ikakoM5SD.h"

ikakoM5SD::ikakoM5SD(fs::SDFS *fs)
{
    my_sd = fs;
}

void ikakoM5SD::setup()
{
    my_sd->begin(4);
    card_type = my_sd->cardType();
    card_size = my_sd->cardSize() / (1024 * 1024);
}

bool ikakoM5SD::create_dir(char *path)
{
    return (my_sd->mkdir(path)) ? true : false;
}

bool ikakoM5SD::remove_dir(char *path)
{
    return (my_sd->rmdir(path)) ? true : false;
}

bool ikakoM5SD::read(char *path, uint8_t buffer)
{
    File file = my_sd->open(path);
    if(!file) return false;
    buffer = file.read();
    file.close();
    return true;
}

bool ikakoM5SD::read_bytes(char *path, char *buffer, size_t size)
{
    File file = my_sd->open(path);
    if(!file) return false;
    file.readBytes(buffer, size);
    file.close();
    return true;
}

bool ikakoM5SD::read_bytes_until(char *path, uint8_t *buffer, size_t size, char terminator)
{
    File file = my_sd->open(path);
    if(!file) return false;
    file.readBytesUntil(terminator, buffer, size);
    file.close();
    return true;
}

bool ikakoM5SD::read_string(char *path, char *buffer, size_t size)
{
    File file = my_sd->open(path);
    if(!file) return false;
    memcpy(buffer, file.readString().c_str(), size);
    file.close();
    return true;
}

bool ikakoM5SD::read_string_until(char *path, char *buffer, char terminator)
{
    File file = my_sd->open(path);
    if(!file) return false;
    String string = file.readStringUntil(terminator);
    memcpy(buffer, string.c_str(), sizeof(string.c_str()));
    file.close();
    return true;
}

bool ikakoM5SD::write_file(char *path, char *message)
{
    File file = my_sd->open(path, FILE_WRITE);
    if(!file) return false;
    if(!file.print(message)) return false;
    file.close();
    return true;
}

bool ikakoM5SD::append_file(char *path, char *message)
{
    File file = my_sd->open(path, FILE_APPEND);
    if(!file) return false;
    if(!file.print(message)) return false;
    file.close();
    return true;
}

bool ikakoM5SD::rename_file(char *path1, char *path2)
{
    return my_sd->rename(path1, path2) ? true : false;
}

bool ikakoM5SD::delete_file(char *path)
{
    return my_sd->remove(path) ? true : false;
}

int ikakoM5SD::get_card_type()
{
    return card_type;
}

int ikakoM5SD::get_card_size()
{
    return card_size;
}
# サンプルコード
```C
#include <Arduino.h>
#include <ikakoM5SD.h>
#include <M5Stack.h>

ikakoM5SD sd(&SD);

void setup()
{
    M5.begin(true, false);
    sd.setup();
    sd.create_dir("/hoge");
    sd.write_file("/hoge/hoge.txt", "hoge\n");
    sd.append_file("/hoge/hoge.txt", "hoge hoge hoge hoge\n");
    Serial.printf("type:%d  size:%d  ", sd.get_card_type(), sd.get_card_size());
    Serial.println("");
}

void loop()
{

}
```
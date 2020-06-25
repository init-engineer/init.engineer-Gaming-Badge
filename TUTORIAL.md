# Arduino Pro Mini燒錄教學

[![Build Status](https://img.shields.io/badge/facebook-@init.kobeengineer-3b5998.svg)](https://www.facebook.com/init.kobeengineer)
[![Build Status](https://img.shields.io/badge/facebook-@init.kobeengineer-3b5998.svg)](https://www.facebook.com/kaobei.engineer)
[![Build Status](https://img.shields.io/badge/twitter-@kaobei_engineer-55acee.svg)](https://twitter.com/kaobei_engineer)
[![Build Status](https://img.shields.io/badge/plurk-@kaobei_engineer-ff574d.svg)](https://www.plurk.com/kaobei_engineer)

### 0.	需要準備的材料有

  - 純靠北工程師 ENGINEER 電競胸章(以下簡稱”胸章”)
  - 燒錄線(需另購)(以CH340燒錄現為例)
  - Arduino IDE (官方下載網址:www.arduino.cc/en/main/software?setlang=cn)
  - FastLED.h Library (可從Arduino IDE內下載)(GitHub網址: https://github.com/FastLED/FastLED)
  - 待燒錄的程式(以init.kobeengineer.gear.ino為例)
  - 正常的電腦(以Windows 10為例)
  - 萬能的雙手

### 1.	燒錄前準備

1-1:先將胸章外殼拆開，小心翼翼將Arduino Pro Mini取出。

1-2:將燒錄線Pin腳與Arduino Pro Mini對接。
![1-1](https://i.imgur.com/v0jzizZ.jpg)
| Arduino Pro Mini | CH340燒錄線 |
| ------ | ------ |
| DTR | DTR |
| TXD | RXD |
| RXD | TXD |
| VCC | VCC(5V) |
| GND | CTS |
| GND | GND |

1-3將燒錄線插上電腦，至裝置管理員確認是否抓取驅動，如沒有，請自行上網搜尋下載該燒錄線驅動程式，每款燒錄線驅動程式可能會有所不同。
![1-3](https://i.imgur.com/kbLgyM3.png)

### 2.	Arduino IDE下載(以Windows 10為例)
##### 這裡提供兩種安裝方式，以下方式擇一即可。

2-1-1(適用於大多數Windows裝置)至Arduino官方網站(www.arduino.cc)，至Software，點選Windows安裝包，下載後依照指示安裝。
![2-1](https://i.imgur.com/1dyhtpN.png)

2-2-1(適用於Windows 10、Windows 10S等)至Windows Store搜尋Arduino IDE，點擊安裝後啟動即可。
![2-2](https://i.imgur.com/nl7yXJk.png)

### 3.	Library安裝
##### 這裡提供兩種安裝方式，以下方式擇一即可。

3-1-1開啟Arduino IDE後點擊"草稿碼->匯入程式庫->管理程式庫”。
![3-1-1](https://i.imgur.com/xxER4Qu.png)

3-1-2搜尋FastLED後，下方FastLED點擊”安裝”。
![3-1-2](https://i.imgur.com/LRFZ79R.png)

3-1-3至”檔案->範例->第三方程式庫的範例”檢查是否有FastLED。
![3-1-3](https://i.imgur.com/UecQCst.png)

3-2-1至 https://github.com/FastLED/FastLED 網頁，”Clone or download”點選後點擊”Download ZIP”。
![3-2-1](https://i.imgur.com/tOYIwJe.png)

3-2-2至”草稿碼->匯入程式庫->加入.ZIP程式庫…”，選擇剛剛的”FastLED-master.zip”下載位置。
![3-2-2](https://i.imgur.com/4Y7zBtW.png)

3-2-3至”檔案->範例->第三方程式庫的範例”檢查是否有FastLED。
![3-2-3](https://i.imgur.com/aKhbrfO.png)

### 4.	Arduino開發板與序列埠選擇

4-1至”工具->開發板:”選擇Arduino Pro or Pro Mini”。
![4-1](https://i.imgur.com/IiA4EVj.png)

4-2至”工具->處理器:”選擇”ATmega328P (5V, 16MHz)”(胸章採用此版本)。
![4-2](https://i.imgur.com/GYYvXn2.png)

4-3至”工具->序列埠”選擇燒錄線的序列埠(請至1-3查看)。
![4-3](https://i.imgur.com/JRJLTBa.png)

### 5.	將程式燒錄至Arduino

5-1將下載後的.ino檔案放至資料夾內(資料夾名稱需與.ino檔案名稱相同)。
![5-1](https://i.imgur.com/fJ3hy3r.png)

5-2開啟.ino檔案後點擊”以燒錄器上傳”，待下方顯示”上傳完成”。
![5-2](https://i.imgur.com/FIOUNLh.png)

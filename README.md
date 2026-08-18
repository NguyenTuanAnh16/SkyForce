# Game Bắn Máy Bay 2D

## 1. Giới thiệu

**Game Bắn Máy Bay 2D** là trò chơi bắn máy bay được xây dựng bằng **C++** kết hợp với thư viện **SDL2**. Người chơi điều khiển máy bay chiến đấu, tiêu diệt kẻ địch, thu thập vật phẩm và hoàn thành các màn chơi.

Các chức năng chính của hệ thống:

* Menu chính
* Chọn máy bay
* Chọn màn chơi
* Điều khiển máy bay
* Hệ thống kẻ địch
* Hệ thống đạn
* Hệ thống vật phẩm
* Hệ thống hiệu ứng
* Quản lý máu và điểm số
* Hệ thống Pause
* Màn hình Win / Lost
* Âm thanh và nhạc nền
* Cài đặt FPS

---

## 2. Công nghệ và môi trường

### 2.1. Công nghệ

* **C++**
* **SDL2**
* **SDL2_image**
* **SDL2_mixer**

### 2.2. Môi trường phát triển

* **Windows**
* **Code::Blocks**
* **MinGW**
* **Git / GitHub**

### 2.3. Yêu cầu cài đặt

Để chạy chương trình, cần chuẩn bị:

* Trình biên dịch C++ hỗ trợ **C++11 trở lên**.
* Thư viện **SDL2**.
* Thư viện **SDL2_image**.
* Thư viện **SDL2_mixer**.
* Đảm bảo thư mục `ResourceManager` được đặt đúng vị trí trong project khi chạy chương trình.
* Đảm bảo các file `.dll` cần thiết của SDL2 được đặt đúng vị trí để chương trình có thể khởi chạy.

---

## 3. Cấu trúc thư mục

```text
Game/
│
├── ResourceManager/
│   ├── BackGround/
│   ├── Enemy/
│   ├── Effect/
│   ├── Item/
│   ├── Menu/
│   ├── Music/
│   ├── Player/
│   ├── Starship/
│   └── Weapon/
│
├── BackgroundSystem.*
├── EnemySystem.*
├── EffectSystem.*
├── WeaponSystem.*
├── Player.*
├── Menu.*
├── ResourceManager.*
├── Game.*
└── README.md
```

### Mô tả các thành phần

| Thành phần         | Chức năng                                             |
| ------------------ | ----------------------------------------------------- |
| `ResourceManager/` | Lưu trữ hình ảnh, âm thanh và các tài nguyên của game |
| `BackgroundSystem` | Quản lý background và chuyển động màn chơi            |
| `EnemySystem`      | Quản lý kẻ địch                                       |
| `EffectSystem`     | Quản lý các hiệu ứng                                  |
| `WeaponSystem`     | Quản lý đạn và vũ khí                                 |
| `Player`           | Xử lý máy bay và trạng thái người chơi                |
| `Menu`             | Xử lý giao diện và menu                               |
| `ResourceManager`  | Quản lý việc tải và sử dụng tài nguyên                |
| `Game`             | Quản lý vòng đời và hoạt động chính của game          |

---

## 4. Các chức năng chính

### Menu chính

Cho phép người chơi:

* Bắt đầu trò chơi
* Chọn máy bay
* Chọn màn chơi
* Cài đặt
* Thoát game

### Điều khiển máy bay

Người chơi có thể điều khiển máy bay bằng bàn phím để di chuyển và sử dụng vũ khí tiêu diệt kẻ địch.

### Hệ thống kẻ địch

Game có hệ thống quản lý nhiều loại kẻ địch với vị trí, chuyển động và khả năng tấn công khác nhau.

### Hệ thống vũ khí

Quản lý:

* Đạn của người chơi
* Đạn của kẻ địch
* Tốc độ đạn
* Vị trí xuất hiện đạn
* Va chạm giữa đạn và đối tượng

### Hệ thống vật phẩm

Người chơi có thể thu thập các vật phẩm xuất hiện trong màn chơi để nhận các hiệu ứng hỗ trợ.

### Hệ thống hiệu ứng

Quản lý các hiệu ứng hình ảnh như:

* Hiệu ứng bắn
* Hiệu ứng va chạm
* Hiệu ứng nổ
* Hiệu ứng hồi máu
* Các hiệu ứng hỗ trợ khác

### Máu và điểm số

Trong quá trình chơi, hệ thống theo dõi:

* Máu của người chơi
* Điểm số
* Trạng thái sống / thua
* Điều kiện hoàn thành màn chơi

### Pause, Win và Lost

Game cung cấp các trạng thái:

* **Pause:** Tạm dừng trò chơi.
* **Win:** Người chơi hoàn thành màn chơi.
* **Lost:** Người chơi thất bại.

### Âm thanh và nhạc nền

Sử dụng **SDL2_mixer** để quản lý:

* Nhạc nền
* Âm thanh bắn đạn
* Âm thanh va chạm
* Âm thanh hiệu ứng trong game

### Cài đặt FPS

Cho phép người chơi điều chỉnh giới hạn FPS của game để phù hợp với thiết bị.

---

## 5. Cách chạy chương trình

1. Clone hoặc tải project về máy.
2. Mở project bằng **Code::Blocks**.
3. Kiểm tra cấu hình SDL2, SDL2_image và SDL2_mixer.
4. Kiểm tra thư mục `ResourceManager`.
5. Đảm bảo các file tài nguyên và `.dll` cần thiết nằm đúng vị trí.
6. Build project.
7. Chạy chương trình.

---

## 6. Mục tiêu của project

Project được thực hiện nhằm áp dụng kiến thức lập trình C++ và thư viện SDL2 vào việc xây dựng một trò chơi 2D hoàn chỉnh.

Thông qua project, các kiến thức được áp dụng gồm:

* Lập trình hướng đối tượng C++
* Quản lý tài nguyên
* Xử lý sự kiện và bàn phím
* Xử lý va chạm
* Quản lý trạng thái game
* Xử lý animation và hiệu ứng
* Quản lý âm thanh
* Quản lý FPS và thời gian
* Làm việc với Git / GitHub

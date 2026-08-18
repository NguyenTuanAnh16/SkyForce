Game Bắn Máy Bay 2D
1. Giới thiệu
Game bắn máy bay 2D được xây dựng bằng C++ và thư viện SDL2. Người chơi điều khiển máy bay, tiêu diệt kẻ địch, thu thập vật phẩm và hoàn thành các màn chơi.
Phạm vi của hệ thống gồm:
•	Menu chính
•	Chọn máy bay
•	Chọn màn chơi
•	Điều khiển máy bay
•	Hệ thống kẻ địch
•	Hệ thống đạn
•	Hệ thống vật phẩm
•	Hiệu ứng
•	Máu và điểm số
•	Pause, Win, Lost
•	Âm thanh và nhạc nền
•	Cài đặt FPS
2. Công nghệ và môi trường
Công nghệ
•	C++
•	SDL2
•	SDL2_image
•	SDL2_mixer
Môi trường
•	Windows
•	Code::Blocks
•	MinGW
•	Git / GitHub
Yêu cầu cài đặt
•	Cài đặt trình biên dịch C++ hỗ trợ C++11 trở lên.
•	Cài đặt SDL2.
•	Cài đặt SDL2_image.
•	Cài đặt SDL2_mixer.
•	Đảm bảo thư mục ResourceManager nằm đúng vị trí khi chạy chương trình.
3. Cấu trúc thư mục
Game/
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


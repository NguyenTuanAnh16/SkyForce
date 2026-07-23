#pragma once

class Movement {
public:
    // Hàm xử lý kiểu bay lượn hình sin và rớt từ trên xuống cho quái thường
    // Lưu ý: x, y, và waveOffset được truyền dưới dạng tham chiếu (&) để thay đổi giá trị gốc
    static void updateNormalEnemy(float& x, float& y, float startX, float& waveOffset, float speed, float deltaTime, float screenHeight);

    // Hàm xử lý kiểu bay bám theo người chơi cho Boss
    static void updateBossEnemy(float& x, float playerX, float speed);
};

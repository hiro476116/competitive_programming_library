#include <chrono>

namespace utility {
  struct timer {
    private:
    const std::chrono::system_clock::time_point start;

    public:
    constexpr unsigned time_limit = 2000 - 20;  // 20 ms くらいは余裕を持たせる

    timer() noexcept : start(std::chrono::system_clock::now()) {}

    // 経過時間 (ms) を返す
    [[nodiscard]] auto elapsed() const {
      using namespace std::chrono;
      return duration_cast<milliseconds>(system_clock::now() - start).count();
    }

    // 経過時間が制限時間の num/den 倍未満かを返す
    // 例えば frac<1, 2>() は経過時間が制限時間の 1/2 未満かを返す
    template <unsigned num, unsigned den> [[nodiscard]] bool frac() const {
      return elapsed() < time_limit * num / den;
    }

    // 経過時間が制限時間未満かを返す
    [[nodiscard]] bool good() const { return elapsed() < time_limit; }
  };
}  // namespace utility

int main() {
  const utility::timer tm;

  // 制限時間内のループ
  while (tm.good()) {
    // なんかする
  }
}
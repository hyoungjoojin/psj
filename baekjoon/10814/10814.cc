#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Member {
public:
  unsigned int get_index() const;
  unsigned short get_age() const;

  void set_index(unsigned int);

  friend std::istream &operator>>(std::istream &istream, Member &member) {
    istream >> member.age_ >> member.name_;
    return istream;
  }

  friend std::ostream &operator<<(std::ostream &ostream, const Member &member) {
    ostream << member.age_ << ' ' << member.name_ << '\n';
    return ostream;
  }

private:
  unsigned int index_;
  unsigned short age_;
  std::string name_;
};

void solution(std::vector<Member> &);

int main(int argc, const char **argv) {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int n = 0;
  std::cin >> n;

  std::vector<Member> members(n);
  for (int i = 0; i < n; i++) {
    std::cin >> members[i];
    members[i].set_index(i);
  }

  solution(members);

  for (const Member &member : members) {
    std::cout << member;
  }

  return 0;
}

unsigned int Member::get_index() const { return index_; }
unsigned short Member::get_age() const { return age_; }

void Member::set_index(unsigned int index) { index_ = index; }

void solution(std::vector<Member> &members) {
  std::sort(members.begin(), members.end(),
            [](const Member &m1, const Member &m2) {
              unsigned int age1 = m1.get_age(), age2 = m2.get_age();
              if (age1 == age2) {
                return m1.get_index() < m2.get_index();
              }

              return age1 < age2;
            });
}

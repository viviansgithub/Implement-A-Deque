#include <gtest/gtest.h>
#include <initializer_list>
#include <string>
#include "myDeque.hpp"

// Default constructor
TEST(MyDequeTest, DefaultConstructor) {
  MyDeque<std::string> deque;
  EXPECT_EQ(deque.size(), 0);
}

// Constructor with size
TEST(MyDequeTest, ConstructorWithSizeDouble) {
  const int N {5};
  MyDeque<double> deque(N);
  EXPECT_EQ(deque.size(), N);
  for (int i = 0; i < N; ++i) {
    EXPECT_DOUBLE_EQ(deque[i], 0.0);
  }
}

TEST(MyDequeTest, ConstructorWithSizeString) {
  const int N {10};
  MyDeque<double> deque(N);
  EXPECT_EQ(deque.size(), N);
  for (int i = 0; i < N; ++i) {
    EXPECT_DOUBLE_EQ(deque[i], 0.0);
  }
}

// Constructor with initializer list
TEST(MyDequeTest, ConstructorWithInitializerListInt) {
  MyDeque<int> deque {1, 2, 3, 4};
  EXPECT_EQ(deque.size(), 4);
  EXPECT_EQ(deque[0], 1);
  EXPECT_EQ(deque[1], 2);
  EXPECT_EQ(deque[2], 3);
  EXPECT_EQ(deque[3], 4);
}

TEST(MyDequeTest, ConstructorWithInitializerChar) {
  MyDeque<char> deque{'a', 'b', 'c', 'd', 'e'};
  EXPECT_EQ(deque.size(), 5);
  EXPECT_EQ(deque[0], 'a');
  EXPECT_EQ(deque[1], 'b');
  EXPECT_EQ(deque[2], 'c');
  EXPECT_EQ(deque[3], 'd');
  EXPECT_EQ(deque[4], 'e');
}

// front and back tests
TEST(MyDequeTest, FrontSizeOne) {
  MyDeque<char> deque{'a'};
  EXPECT_EQ(deque.front(), 'a');
}

TEST(MyDequeTest, BackSizeOne) {
  MyDeque<char> deque{'a'};
  EXPECT_EQ(deque.back(), 'a');
}

TEST(MyDequeTest, ConstFront) {
  const MyDeque<char> deque{'a', 'b', 'c', 'd', 'e'};
  EXPECT_EQ(deque.front(), 'a');
}

TEST(MyDequeTest, ConstBack) {
  const MyDeque<char> deque{'a', 'b', 'c', 'd', 'e'};
  EXPECT_EQ(deque.back(), 'e');
}

TEST(MyDequeTest, modifyViaFront) {
  MyDeque<int> deque{7, 6, 5, 4, 3};
  EXPECT_EQ(deque.front(), 7);
  deque.front() = 1;
  EXPECT_EQ(deque.front(), 1);
}

TEST(MyDequeTest, modifyViaBack) {
  MyDeque<int> deque{7, 6, 5, 4, 3};
  EXPECT_EQ(deque.back(), 3);
  deque.back() = 8;
  EXPECT_EQ(deque.back(), 8);
}

// tests of push_back and push_front
TEST(MyDequeTest, PushBack) {
  MyDeque<int> deque(2);
  deque.push_back(1);
  EXPECT_EQ(deque.size(), 3);
  EXPECT_EQ(deque[2], 1);
}

TEST(MyDequeTest, PushFront) {
  MyDeque<int> deque(2);
  deque.push_front(1);
  EXPECT_EQ(deque.size(), 3);
  EXPECT_EQ(deque[0], 1);
}

TEST(MyDequeTest, PushBackNotEmpty) {
  MyDeque<std::string> deque;
  EXPECT_TRUE(deque.empty());
  deque.push_back("hello world");
  EXPECT_FALSE(deque.empty());
}

TEST(MyDequeTest, speedPushFrontPushBack) {
  MyDeque<int> deque;
  const int N = 1'000'000;
  for (int i = 0; i < N; ++i) {
    deque.push_front(N - i - 1);
    deque.push_back(N + i);
  }
  for (int i = 0; i < 2*N; ++i) {
    EXPECT_EQ(deque[i], i);
  }
}

// tests of pop_front and pop_back
TEST(MyDequeTest, PopBack) {
  MyDeque<int> deque{1, 2, 3};
  deque.pop_back();
  EXPECT_EQ(deque.size(), 2);
  EXPECT_EQ(deque[0], 1);
  EXPECT_EQ(deque[1], 2);
}

TEST(MyDequeTest, PopFront) {
  MyDeque<int> deque {1, 2, 3};
  deque.pop_front();
  EXPECT_EQ(deque.size(), 2);
  EXPECT_EQ(deque[0], 2);
  EXPECT_EQ(deque[1], 3);
}

TEST(MyDequeTest, PopFrontAndFrontChar) {
  MyDeque<char> deque {'a', 'b', 'c', 'd', 'e'};
  EXPECT_EQ(deque.front(), 'a');
  deque.pop_front();
  EXPECT_EQ(deque.front(), 'b');
  deque.pop_front();
  EXPECT_EQ(deque.front(), 'c');
  deque.pop_front();
  EXPECT_EQ(deque.front(), 'd');
  deque.pop_front();
  EXPECT_EQ(deque.front(), 'e');
  deque.pop_front();
  EXPECT_TRUE(deque.empty());
}

TEST(MyDequeTest, PopBackAndBackChar) {
  MyDeque<char> deque {'a', 'b', 'c', 'd', 'e'};
  EXPECT_EQ(deque.back(), 'e');
  deque.pop_back();
  EXPECT_EQ(deque.back(), 'd');
  deque.pop_back();
  EXPECT_EQ(deque.back(), 'c');
  deque.pop_back();
  EXPECT_EQ(deque.back(), 'b');
  deque.pop_back();
  EXPECT_EQ(deque.back(), 'a');
  deque.pop_back();
  EXPECT_TRUE(deque.empty());
}

TEST(MyDequeTest, AlternatePopFrontAndBack) {
  MyDeque<char> deque {'a', 'b', 'c', 'd', 'e'};
  EXPECT_EQ(deque.back(), 'e');
  deque.pop_back();
  EXPECT_EQ(deque.front(), 'a');
  deque.pop_front();
  EXPECT_EQ(deque.back(), 'd');
  deque.pop_back();
  EXPECT_EQ(deque.front(), 'b');
  deque.pop_front();
  EXPECT_EQ(deque.back(), 'c');
  deque.pop_back();
  EXPECT_TRUE(deque.empty());
}


// interaction of push and pop
TEST(MyDequeTest, sizeOnePushBackPopFront) {
  MyDeque<int> deque;
  deque.push_back(5);
  deque.pop_front();
  EXPECT_TRUE(deque.empty());
  // try to trigger seg fault
  deque.push_front(5);
  EXPECT_EQ(deque[0], 5);
}

TEST(MyDequeTest, sizeOnePushFrontPopBack) {
  MyDeque<int> deque;
  deque.push_front(5);
  deque.pop_back();
  EXPECT_TRUE(deque.empty());
  // try to trigger seg fault
  deque.push_back(5);
  EXPECT_EQ(deque[0], 5);
}

TEST(MyDequeTest, TriggerRebalance) {
  MyDeque<int> deque;
  deque.push_front(2);
  deque.push_front(1);
  deque.push_back(3);
  deque.pop_back();
  EXPECT_EQ(deque.size(), 2);
  EXPECT_EQ(deque[0], 1);
  EXPECT_EQ(deque[1], 2);
  deque.pop_back();
  EXPECT_EQ(deque.size(), 1);
  EXPECT_EQ(deque[0], 1);
  deque.pop_back();
  deque.push_back(10);
  EXPECT_EQ(deque[0], 10);
}

TEST(MyDequeTest, RebalanceQuickly) {
  MyDeque<int> deque;
  const int N = 1'000'000;
  for (int i = N-1; i >=0; --i) {
    deque.push_front(i);
  }
  for (int i = 0; i < N; ++i) {
    EXPECT_EQ(deque[i], i);
  }
  for (int i = 0; i < N; ++i) {
    deque.pop_back();
  }
  EXPECT_TRUE(deque.empty());
  deque.push_back(23);
  EXPECT_EQ(deque[0], 23);
}

TEST(MyDequeTest, PushBackPopFrontAndFront) {
  MyDeque<char> deque;
  deque.push_back('a');
  EXPECT_EQ(deque.front(), 'a');
  EXPECT_EQ(deque.back(), 'a');
  deque.push_back('b');
  EXPECT_EQ(deque.front(), 'a');
  EXPECT_EQ(deque.back(), 'b');
  deque.pop_front();
  EXPECT_EQ(deque.front(), 'b');
  EXPECT_EQ(deque.back(), 'b');
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

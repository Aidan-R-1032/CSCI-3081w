#include "stack.h"

#include "gtest/gtest.h"

class StackTest : public ::testing::Test {
 public:
  void SetUp() {}
  void TearDown() {}
};
int triple(int x) { return x * 3; }
bool isOdd(int x) { return (x % 2 == 1); }
int product(int x, int y) { return x * y; }

Stack UptoFive({1, 2, 3, 4, 5});
Stack EvenUpToTen({2, 4, 6, 8, 10});
Stack CapTenStack = Stack(10);
TEST_F(StackTest, CreationAndInitialization) {
  Stack CopyOfUptoFive(UptoFive);
  Stack Odds_to_11 = Stack({1, 3, 5, 7, 9, 11});
  Stack Odds_to_11_too({1, 3, 5, 7, 9, 11});
  Stack Odds_from_11_to_1({11, 9, 7, 5, 3, 1});
  EXPECT_EQ(CopyOfUptoFive.size(), UptoFive.size())
      << "size should not change in copy";
  EXPECT_EQ(CopyOfUptoFive.getCapacity(), UptoFive.getCapacity())
      << "capacity should not change when copied";
  for (int i = 0; i < CopyOfUptoFive.size(); i++) {
    EXPECT_EQ(CopyOfUptoFive[i], UptoFive[i])
        << "elements of copy & original are not in the same position";
  }
  EXPECT_FALSE(EvenUpToTen == UptoFive) << "False positive ==operator";
  EXPECT_TRUE(Odds_to_11 == Odds_to_11_too)
      << "Equal assignment operator failure";
  EXPECT_FALSE(Odds_from_11_to_1 == Odds_to_11)
      << "Order should matter with ==operator";

  std::string expect_1 = "[1, 2, 3, 4, 5]\n";
  std::string expect_2 = "[1, 2, 3, 4, 5]\n";
  bool expect_3 = true;
  bool expect_4 = true;
  ASSERT_NO_THROW(std::cout << UptoFive << std::endl;)
      << "Should be able to output stack without error";
  testing::internal::CaptureStdout();
  std::cout << UptoFive << std::endl;
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  std::cout << CopyOfUptoFive << std::endl;
  std::string output2 = testing::internal::GetCapturedStdout();

  bool output4 = (UptoFive == CopyOfUptoFive);
  EXPECT_EQ(expect_1, output1) << "Creating & Initializing Stack failure";
  EXPECT_EQ(expect_2, output2) << "Could not copy Stack";

  Stack emptyStack;
  ASSERT_NO_THROW(emptyStack = Stack()) << "Empty Stack should not segfault";
  ASSERT_NO_THROW(Stack(0))
      << "Stack of capacity 0 should still be able to be created";
  ASSERT_NO_THROW(Stack(10000))
      << "Stack of capacity 1000 should still be able to be created";
  bool output3 = emptyStack.isEmpty();
  EXPECT_EQ(expect_3, output3) << "Could not create empty Stack";
  EXPECT_EQ(emptyStack.getCapacity(), 1000)
      << "Empty stacks must have a default capacity of 1000";
  EXPECT_EQ(expect_4, output4) << "Stack copy not equal to original stack";
}

TEST_F(StackTest, IndexingAndRemoving) {
  int original_UTF_size = UptoFive.size();
  int expect_1 = 1;
  int output1 = UptoFive.pop();
  int expect_2 = 2;
  int output2 = UptoFive.pop();
  int pop_UTF_size = UptoFive.size();
  EXPECT_EQ(original_UTF_size, pop_UTF_size + 2)
      << "Size not decremented properly after a pop";
  bool expect_3 = true;
  int output3 = (UptoFive == Stack({3, 4, 5}));
  int expect_4 = 8;
  int output4 = EvenUpToTen[3];
  bool expect_5 = true;
  bool output5 = (EvenUpToTen == (Stack{2, 4, 6, 8, 10}));
  int expect_6 = 2;

  testing::internal::CaptureStdout();
  EXPECT_NO_THROW({ EvenUpToTen.peek(); })
      << "Should not throw error to peek an initialized stack";
  std::string output_msg = testing::internal::GetCapturedStdout();
  EXPECT_NE(output_msg, "Undeflow\nProgram Terminated\n")
      << "Should not output underflow error";

  int output6 = EvenUpToTen.peek();

  int expect_7 = 1;
  int output7;
  int size_of_EUTT = EvenUpToTen.size();
  int capacity_of_EUTT = EvenUpToTen.getCapacity();
  EXPECT_NO_THROW({ output7 = EvenUpToTen.indexOf(4); })
      << "Errors should not be thrown for indexOf";
  int size_after_indexOf_EUTT = EvenUpToTen.size();
  int capacity_after_indexOf_EUTT = EvenUpToTen.getCapacity();
  EXPECT_EQ(size_of_EUTT, size_after_indexOf_EUTT)
      << "size should not change after calling index of";
  EXPECT_EQ(capacity_of_EUTT, capacity_after_indexOf_EUTT)
      << "capacity should not change after calling index of";
  for (int i = 0; i < size_of_EUTT; i++) {
    EXPECT_EQ(i, EvenUpToTen.indexOf(EvenUpToTen[i]))
        << "IndexOf each element should return its corresponding index";
  }
  int expect_8 = -1;
  int output8;
  EXPECT_NO_THROW({ output8 = EvenUpToTen.indexOf(3); })
      << "Errors should not be thrown of indexOf even when element DNE";
  size_after_indexOf_EUTT = EvenUpToTen.size();
  capacity_after_indexOf_EUTT = EvenUpToTen.getCapacity();
  EXPECT_EQ(size_of_EUTT, size_after_indexOf_EUTT)
      << "size should not change after calling index of even when element DNE";
  EXPECT_EQ(capacity_of_EUTT, capacity_after_indexOf_EUTT)
      << "capacity should not change after calling index of even when element "
         "DNE";

  int cap_before_clear = UptoFive.getCapacity();
  EXPECT_NO_THROW({ UptoFive.clear(); })
      << "Clearing should not throw an error";

  testing::internal::CaptureStdout();
  EXPECT_DEATH({ UptoFive.peek(); }, "")
      << "Peeking from an empty stack should yield underflow error";
  output_msg = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output_msg, "Undeflow\nProgram Terminated\n")
      << "Peeking from from empty stack should not output underflow error";

  testing::internal::CaptureStdout();
  EXPECT_DEATH({ UptoFive.pop(); }, "")
      << "Popping from an empty stack should yield underflow error";
  output_msg = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output_msg, "Undeflow\nProgram Terminated\n")
      << "Popping from empty stack should not output underflow error";

  EXPECT_EQ(expect_1, output1) << "First element not returned";
  EXPECT_EQ(expect_2, output2) << "Next element not set to first & returned";
  EXPECT_EQ(expect_3, output3) << "Stack is missing/did not remove elements";
  EXPECT_EQ(expect_4, output4) << "Indexing not working properly";
  EXPECT_EQ(expect_5, output5) << "Indexing removed element from stack";
  EXPECT_EQ(expect_6, output6) << "Could not peek from top of stack";
  EXPECT_EQ(expect_7, output7)
      << "Incorrect index returned for element in Stack";
  EXPECT_EQ(expect_8, output8)
      << "Incorrectly provided index for non-existent element";
  EXPECT_TRUE(UptoFive.isEmpty()) << "Could not clear stack";
  EXPECT_TRUE(UptoFive.size() == 0) << "Stack size not reset after clear";
  EXPECT_EQ(UptoFive.getCapacity(), cap_before_clear)
      << "Capacity should not be changed after clearing";
  EXPECT_THROW(EvenUpToTen[-1], std::out_of_range);
}
TEST_F(StackTest, PushingAndCapacity) {
  Stack EvenUpToFourteen(EvenUpToTen);
  int original_EUTF_size = EvenUpToFourteen.size();

  testing::internal::CaptureStdout();
  EXPECT_NO_THROW({ EvenUpToFourteen.push(12); })
      << "If there is space on the stack, it should be able to be pushed to "
         "without error";
  std::string output_msg = testing::internal::GetCapturedStdout();
  EXPECT_NE(output_msg, "Overflow\nProgram Terminated\n")
      << "Pushing to a non-full stack should not display there was an overflow "
         "error";

  EvenUpToFourteen.push(14);
  int push_EUTF_size = EvenUpToFourteen.size();
  EXPECT_EQ(original_EUTF_size, push_EUTF_size - 2)
      << "Did not increment size properly after push";
  for (int i = 10; i > 0; i--) {
    CapTenStack.push(i);
  }

  testing::internal::CaptureStdout();
  EXPECT_DEATH({ CapTenStack.push(1000); }, "")
      << "Pushing to a full stack should yield error";
  output_msg = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output_msg, "Overflow\nProgram Terminated\n")
      << "Pushing to full stack should display there was an overflow error";

  Stack MT = Stack();
  Stack CapTenStackCopy(CapTenStack);
  int CTSC_old_cap = CapTenStackCopy.getCapacity();
  EXPECT_NO_THROW({ CapTenStackCopy.updateCapacity(12); })
      << "updateCapactity should not throw an error";
  int CTSC_new_cap = CapTenStackCopy.getCapacity();

  std::string expect_1 = "[14, 12, 2, 4, 6, 8, 10]\n";
  std::string expect_2 = "[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]\n";

  testing::internal::CaptureStdout();
  std::cout << EvenUpToFourteen << std::endl;
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  std::cout << CapTenStack << std::endl;
  std::string output2 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(expect_1, output1) << "Could not push items to initialized stack";
  EXPECT_EQ(expect_2, output2)
      << "Could not push items to uninitialized capped stack";
  EXPECT_EQ(10, CapTenStack.getCapacity())
      << "Get Capacity Function Not Working";
  EXPECT_TRUE(CapTenStack.isFull())
      << "Capped stack is not considered full when it reached capacity";
  EXPECT_NE(CTSC_old_cap, CTSC_new_cap) << "Capacity is not being updated";
  EXPECT_FALSE(CapTenStackCopy.isFull())
      << "Incorrectly states that stack is full when it shouldn't be";
  EXPECT_EQ(CTSC_new_cap, 12) << "Capacity should be updated to 12";
  EXPECT_LT(CapTenStackCopy.size(), CapTenStackCopy.getCapacity())
      << "Should not be at (or above) capacity";
  EXPECT_EQ(MT.getCapacity(), 1000)
      << "Uninitialized Stack has the wrong capacity";
}
TEST_F(StackTest, HigherOrder) {
  Stack HighOrderStack({5, 1, 23, 9, 100});
  Stack sorted_stack({1, 5, 9, 23, 100});
  Stack reverse_sorted({100, 23, 9, 5, 1});

  int initialCapacity = HighOrderStack.getCapacity();
  ASSERT_NO_THROW(HighOrderStack.sort())
      << "Sorting should not produce an exception";
  EXPECT_EQ(initialCapacity, HighOrderStack.getCapacity())
      << "Capacity should not change after sorting";
  int HOS_Size = HighOrderStack.size();
  for (int i = 0; i < HOS_Size - 1; i++) {
    EXPECT_EQ(HighOrderStack[i], sorted_stack[i])
        << "Items not in sorted order";
  }

  ASSERT_NO_THROW(HighOrderStack.reverse())
      << "Reversing should not produce an exception";
  EXPECT_EQ(initialCapacity, HighOrderStack.getCapacity())
      << "Capacity should not change after reversing";
  EXPECT_EQ(HOS_Size, HighOrderStack.size())
      << "Size should not change after reversing";
  for (int i = 0; i < HOS_Size - 1; i++) {
    EXPECT_EQ(reverse_sorted[i], HighOrderStack[i]) << "Items not reversed";
  }

  int HOS_size_before = HighOrderStack.size();
  ASSERT_NO_THROW(HighOrderStack.filter(isOdd))
      << "No exception should be thrown for filter";
  EXPECT_EQ(initialCapacity, HighOrderStack.getCapacity())
      << "Capacity should not change after filtering";
  int HOS_size_after = HighOrderStack.size();
  for (int i = 0; i < HighOrderStack.size(); i++) {
    EXPECT_TRUE(isOdd(HighOrderStack[i]))
        << "Item(s) that violate filter condition not removed";
  }
  EXPECT_EQ(HOS_size_before, HOS_size_after + 1)
      << "Size should be decremented after filtering out an element";
  EXPECT_EQ(HighOrderStack.indexOf(100), -1)
      << "IndexOf a removed item is not -1";

  Stack HighOrderStackCopy(HighOrderStack);
  int initialCapacity_HOSC = HighOrderStackCopy.getCapacity();
  int initialSize_HOSC = HighOrderStackCopy.size();
  ASSERT_NO_THROW(HighOrderStackCopy.map(triple))
      << "No exception should be thrown for map";
  EXPECT_EQ(initialCapacity_HOSC, HighOrderStackCopy.getCapacity())
      << "Capacity should not change after mapping";
  int HOSC_size = HighOrderStackCopy.size();
  EXPECT_EQ(initialSize_HOSC, HOSC_size)
      << "Size should not change after mapping";
  for (int i = 0; i < HOSC_size; i++) {
    EXPECT_EQ(HighOrderStack[i] * 3, HighOrderStackCopy[i])
        << "Element(s) not mapped according to passed in function";
  }

  int expect_product = 5 * 23 * 9;
  Stack another_HOSC(HighOrderStack);
  int output_product;
  ASSERT_NO_THROW((output_product = HighOrderStack.reduce(product, 1)))
      << "No exception should be thrown for reduce";
  int HOS_size_reduce = HighOrderStack.size();
  int HOS_cap_reduce = HighOrderStack.getCapacity();
  EXPECT_EQ(HOS_size_reduce, 4) << "Size should not be changed due to reduce";
  EXPECT_EQ(HOS_cap_reduce, initialCapacity)
      << "Capacity should not change after reduce";
  EXPECT_TRUE(HighOrderStack == another_HOSC)
      << "Reducing should not alter stack";
  EXPECT_EQ(expect_product, output_product) << "Incorrect reduce computation";
}

TEST_F(StackTest, ChangingSize) {
  Stack peek_n_pop = Stack(10);
  EXPECT_TRUE(peek_n_pop.isEmpty()) << "Uninitialized stack should be empty";
  int size_iterator = 0;
  for (int i = 10; i > 0; i--) {
    if (i != 1) {
      EXPECT_FALSE(peek_n_pop.isFull())
          << "Stack is only full when capacity is reached";
    }
    size_iterator++;
    EXPECT_NO_THROW({ peek_n_pop.push(i); })
        << "Values should be able to be pushed to the stack";
    EXPECT_FALSE(peek_n_pop.isEmpty())
        << "Stack should not be empty when value(s) have been pushed to it";
    EXPECT_EQ(peek_n_pop[0], i)
        << "Values pushed to the stack should be at index 0";
    EXPECT_EQ(peek_n_pop.indexOf(i), 0)
        << "IndexOf is not working correctly - values pushed to stack should "
           "have index 0";
    EXPECT_EQ(peek_n_pop.size(), size_iterator)
        << "Size not properly incremented with push";
    EXPECT_EQ(peek_n_pop.getCapacity(), 10)
        << "Capacity should not change due to push";
  }
  EXPECT_TRUE(peek_n_pop.isFull())
      << "Stack is full - capacity has been reached";

  std::string error_msg = "Overflow\nProgram Terminated\n";
  testing::internal::CaptureStdout();
  EXPECT_DEATH(peek_n_pop.push(11), "")
      << "Reached capacity - cannot push another item to stack";
  std::string output_msg = testing::internal::GetCapturedStdout();
  EXPECT_EQ(error_msg, output_msg)
      << "Push should display this message when overflow occurs";

  for (int i = 1; i < 11; i++) {
    EXPECT_EQ(peek_n_pop.indexOf(i), i - 1)
        << "Did not move items down the stack correctly when pushing";
  }
  EXPECT_EQ(peek_n_pop.indexOf(11), -1)
      << "Element not in stack should have index of -1";
  int first_item = 0;
  int peek_val = 0;
  int pop_val = 0;
  while (peek_n_pop.size() > 0) {
    first_item = peek_n_pop[0];
    EXPECT_NO_THROW({ peek_val = peek_n_pop.peek(); })
        << "No exception should be thrown by peeking at a non-empty stack";
    EXPECT_NO_THROW({ pop_val = peek_n_pop.pop(); })
        << "No exception should be throw by popping a non-empty stack";
    ASSERT_EQ(peek_val, pop_val)
        << "Peek should be updated every time something is popped";
    ASSERT_EQ(peek_val, first_item)
        << "Peek value should be the first item in the stack";
  }
  error_msg = "Undeflow\nProgram Terminated\n";
  testing::internal::CaptureStdout();
  EXPECT_DEATH(peek_n_pop.pop(), "")
      << "popping an empty stack should throw an exception";
  output_msg = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output_msg, error_msg)
      << "Pop should display this message when underflow error";

  testing::internal::CaptureStdout();
  EXPECT_DEATH(peek_n_pop.peek(), "")
      << "peeking an empty stack should throw an exception";
  output_msg = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output_msg, error_msg)
      << "Peek should display this message when underflow error";
}
TEST_F(StackTest, CapacityChanges) {
  Stack cap_stack;
  Stack clear_stack = Stack();
  EXPECT_NO_THROW({ cap_stack = Stack(0); })
      << "Should be able to initilize a stack of capacity 0";
  EXPECT_THROW({ Stack death_stack(-1); }, std::bad_array_new_length)
      << "Should not be able to initialize a stack with negative capacity";

  std::string error_msg = "Overflow\nProgram Terminated\n";
  testing::internal::CaptureStdout();
  EXPECT_DEATH({ cap_stack.push(1); }, "")
      << "Should not be able to add over capacity";
  std::string output_msg = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output_msg, error_msg)
      << "Pushing past capacity should display this message";

  for (int i = 1; i < 11; i++) {
    EXPECT_NO_THROW(cap_stack.updateCapacity(i))
        << "Update capacity should not throw exception on natural numbers";
    EXPECT_NO_THROW(cap_stack.push(i)) << "Should be able to add a single item "
                                          "every time the capacity increments";
  }
  for (int i = 10; i > -1; i--) {
    cap_stack.updateCapacity(i);
    EXPECT_EQ(cap_stack.getCapacity(), cap_stack.size())
        << "items should be removed when capacity shrinks below previously set "
           "size";
    clear_stack.push(i);
  }
  EXPECT_THROW(cap_stack.updateCapacity(-1), std::bad_array_new_length)
      << "Should not be able to update capacity to a negative number";
  EXPECT_EQ(clear_stack.getCapacity(), 1000)
      << "Although it had elements added to it, the stack capacity should've "
         "been initialized to 1000";
  EXPECT_NO_THROW(clear_stack.clear())
      << "Clearing any stack should not result in an exception";
  EXPECT_EQ(clear_stack.size(), 0) << "size reset to 0 after clear";
  EXPECT_EQ(clear_stack.getCapacity(), 1000)
      << "capacity should not change due to clearing";
  EXPECT_TRUE(clear_stack.isEmpty())
      << "isEmpty should be set to true after clearing stack";
  for (int i = 10; i > -1; i--) {
    EXPECT_THROW(cap_stack[i], std::out_of_range)
        << "should not be able to access stack elements after a clear";
    EXPECT_EQ(cap_stack.indexOf(i), -1)
        << "elements should not be in a cleared list";
  }
}
TEST_F(StackTest, Sorting) {
  Stack some_stack = Stack({5, 2, 7, 1, 3, 4, 6});
  Stack backup(some_stack);
  some_stack.updateCapacity(some_stack.size());
  while (some_stack.getCapacity() != 0) {
    EXPECT_NO_THROW(some_stack.sort()) << "sort should produce no exceptions";
    some_stack.updateCapacity(some_stack.size() - 1);
  }
  EXPECT_NO_THROW(some_stack.sort())
      << "Should still be able sort an empty stack";
}

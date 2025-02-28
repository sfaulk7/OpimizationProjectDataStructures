#include "pch.h"
#include "CppUnitTest.h"
#include "List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DoubleLinkedListTest
{
	TEST_CLASS(DoubleLinkedListTest)
	{
	public:

		TEST_METHOD(DefaultConstructor)
		{
			List<int> list;
			Assert::IsNotNull(&list);
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());
			Assert::AreEqual(0, list.getLength());
		}

		TEST_METHOD(InitializerListConstructor)
		{
			List<int> list = { 9, 8, 7, 6, 5 };

			Iterator<int> iter = list.begin();
			Assert::IsNotNull(&iter);
			Assert::AreEqual(9, *iter);
			iter++;
			Assert::AreEqual(8, *iter);
			iter++;
			Assert::AreEqual(7, *iter);
			iter++;
			Assert::AreEqual(6, *iter);
			iter++;
			Assert::AreEqual(5, *iter);
			Assert::AreEqual(5, list.getLength());
		}

		TEST_METHOD(PushFront)
		{
			List<int> list;
			list.pushFront(1);
			// list should now be { 1 }
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(1, list.getLength());

			list.pushFront(2);
			// list should now be { 2, 1 }
			Assert::AreEqual(2, list.first());
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(2, list.getLength());

			list.pushFront(3);
			// list should now be { 3, 2, 1 }
			Assert::AreEqual(3, list.first());
			Assert::AreEqual(2, *(list.begin()++));
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(3, list.getLength());
		}

		TEST_METHOD(PushBack)
		{
			List<int> list;
			list.pushBack(1);
			// list should now be { 1 }
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(1, list.getLength());

			list.pushBack(2);
			// list should now be { 1, 2 }
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(2, list.last());
			Assert::AreEqual(2, list.getLength());

			list.pushBack(3);
			// list should now be { 1, 2, 3 }
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(2, *(list.begin()++));
			Assert::AreEqual(3, list.last());
			Assert::AreEqual(3, list.getLength());
		}

		TEST_METHOD(PopFront)
		{
			List<int> list = { 1, 2, 3, 4, 5 };
			list.popFront();
			// list should now be { 2, 3, 4, 5 }
			Assert::AreEqual(2, list.first());
			Assert::AreEqual(5, list.last());
			Assert::AreEqual(4, list.getLength());

			list.popFront();
			// list should now be { 3, 4, 5 }
			Assert::AreEqual(3, list.first());
			Assert::AreEqual(5, list.last());
			Assert::AreEqual(3, list.getLength());

			list.popFront();
			// list should now be { 4, 5 }
			Assert::AreEqual(4, list.first());
			Assert::AreEqual(5, list.last());
			Assert::AreEqual(2, list.getLength());

			list.popFront();
			// list should now be { 5 }
			Assert::AreEqual(5, list.first());
			Assert::AreEqual(5, list.last());
			Assert::AreEqual(1, list.getLength());

			list.popFront();
			// list should now be { }
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());
			Assert::AreEqual(0, list.getLength());
		}

		TEST_METHOD(PopBack)
		{
			List<int> list = { 1, 2, 3, 4, 5 };
			list.popBack();
			// list should now be { 1, 2, 3, 4 }
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(4, list.last());
			Assert::AreEqual(4, list.getLength());

			list.popBack();
			// list should now be { 1, 2, 3 }
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(3, list.last());
			Assert::AreEqual(3, list.getLength());

			list.popBack();
			// list should now be { 1, 2 }
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(2, list.last());
			Assert::AreEqual(2, list.getLength());

			list.popBack();
			// list should now be { 1 }
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(1, list.getLength());

			list.popBack();
			// list should now be { }
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());
			Assert::AreEqual(0, list.getLength());
		}

		TEST_METHOD(Insert)
		{
			List<int> list = { 2, 4, 6, 8, 10 };
			list.insert(1, 0);
			// list should now be { 1, 2, 4, 6, 8, 10 }
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(10, list.last());
			Assert::AreEqual(6, list.getLength());

			list.insert(3, 2);
			// list should now be { 1, 2, 3, 4, 6, 8, 10 }
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(10, list.last());
			Assert::AreEqual(7, list.getLength());

			list.insert(5, 4);
			// list should now be { 1, 2, 3, 4, 5, 6, 8, 10 }
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(10, list.last());
			Assert::AreEqual(8, list.getLength());

			list.insert(7, 6);
			// list should now be { 1, 2, 3, 4, 5, 6, 7, 8, 10 }
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(10, list.last());
			Assert::AreEqual(9, list.getLength());

			list.insert(9, 8);
			// list should now be { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(10, list.last());
			Assert::AreEqual(10, list.getLength());

			//Checks list for { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
			Iterator<int> iter = list.begin();
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(4, *iter);
			iter++;
			Assert::AreEqual(5, *iter);
			iter++;
			Assert::AreEqual(6, *iter);
			iter++;
			Assert::AreEqual(7, *iter);
			iter++;
			Assert::AreEqual(8, *iter);
			iter++;
			Assert::AreEqual(9, *iter);
			iter++;
			Assert::AreEqual(10, *iter);
			iter++;

			List<int> emptylist;
			emptylist.insert(1, 0);
			// emptylist should now be { 1 }
			Assert::AreEqual(1, emptylist.first());
			Assert::AreEqual(1, emptylist.last());
			Assert::AreEqual(1, emptylist.getLength());
		}

		TEST_METHOD(Remove)
		{
			int count;
			List<int> list = { 1, 2, 3, 4, 5 };
			count = list.remove(3);
			// list should now be { 1, 2, 4, 5 }
			Assert::AreEqual(1, count);
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(2, *(list.begin()++));
			Assert::AreEqual(4, *(list.begin()++++));
			Assert::AreEqual(5, list.last());
			Assert::AreEqual(4, list.getLength());

			count = list.remove(4);
			// list should now be { 1, 2, 5 }
			Assert::AreEqual(1, count);
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(2, *(list.begin()++));
			Assert::AreEqual(5, list.last());
			Assert::AreEqual(3, list.getLength());

			count = list.remove(2);
			// list should now be { 1, 5 }
			Assert::AreEqual(1, count);
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(5, list.last());
			Assert::AreEqual(2, list.getLength());

			count = list.remove(1);
			// list should now be { 5 }
			Assert::AreEqual(1, count);
			Assert::AreEqual(5, list.first());
			Assert::AreEqual(5, list.last());
			Assert::AreEqual(1, list.getLength());

			count = list.remove(5);
			// list should now be empty { }
			Assert::AreEqual(1, count);
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());
			Assert::AreEqual(0, list.getLength());

			count = list.remove(0);
			// list should still be empty { }
			Assert::AreEqual(0, count);
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());
			Assert::AreEqual(0, list.getLength());

			//Check that it removes multiple of a value
			List<int> list2 = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
			count = list2.remove(3);
			//list2 should now be { 1, 1, 2, 2, 4, 4, 5, 5 }
			Assert::AreEqual(2, count);
			Assert::AreEqual(1, list2.first());
			Assert::AreEqual(5, list2.last());
			Assert::AreEqual(8, list2.getLength());

			count = list2.remove(5);
			//list2 should now be { 1, 1, 2, 2, 4, 4 }
			Assert::AreEqual(2, count);
			Assert::AreEqual(1, list2.first());
			Assert::AreEqual(4, list2.last());
			Assert::AreEqual(6, list2.getLength());

			count = list2.remove(1);
			//list2 should now be { 2, 2, 4, 4 }
			Assert::AreEqual(2, count);
			Assert::AreEqual(2, list2.first());
			Assert::AreEqual(4, list2.last());
			Assert::AreEqual(4, list2.getLength());

			count = list2.remove(4);
			//list2 should now be { 2, 2 }
			Assert::AreEqual(2, count);
			Assert::AreEqual(2, list2.first());
			Assert::AreEqual(2, list2.last());
			Assert::AreEqual(2, list2.getLength());

			count = list2.remove(2);
			//list2 should now be empty { }
			Assert::AreEqual(2, count);
			Assert::AreEqual(0, list2.first());
			Assert::AreEqual(0, list2.last());
			Assert::AreEqual(0, list2.getLength());

			//Check that it removes ALL of a value
			List<int> list3 = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };
			count = list3.remove(5);
			//list3 should now be empty { }
			Assert::AreEqual(13, count);
			Assert::AreEqual(0, list3.first());
			Assert::AreEqual(0, list3.last());
			Assert::AreEqual(0, list3.getLength());
		}

		TEST_METHOD(First)
		{
			List<int> list = { 1, 2, 3, 4, 5 };
			Assert::AreEqual(1, list.first());

			//Test to make sure it won't break if there is nothing in the array
			List<int> emptylist;
			Assert::AreEqual(0, emptylist.first());
		}

		TEST_METHOD(Last)
		{
			List<int> list = { 1, 2, 3, 4, 5 };
			Assert::AreEqual(5, list.last());

			//Test to make sure it won't break if there is nothing in the array
			List<int> emptylist;
			Assert::AreEqual(0, emptylist.last());
		}

		TEST_METHOD(Begin)
		{
			List<int> list = { 1, 2, 3, 4, 5 };

			Iterator<int> iter = list.begin();
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(4, *iter);
			iter++;
			Assert::AreEqual(5, *iter);
			iter--;
			Assert::AreEqual(4, *iter);
			iter--;
			Assert::AreEqual(3, *iter);
			iter--;
			Assert::AreEqual(2, *iter);
			iter--;
			Assert::AreEqual(1, *iter);
		}

		TEST_METHOD(End)
		{
			List<int> list = { 1, 2, 3, 4, 5 };

			Iterator<int> iter = list.end();
			Iterator<int> iter2 (nullptr);

			Assert::IsTrue(iter2 == iter);
		}

		TEST_METHOD(Destroy)
		{
			List<int> list = { 1, 2, 3, 4, 5 };

			Assert::AreEqual(1, list.first());
			Assert::AreEqual(5, list.last());
			Assert::AreEqual(5, list.getLength());

			list.destroy();

			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());
			Assert::AreEqual(0, list.getLength());
		}

		TEST_METHOD(GetLength)
		{
			List<int> list = { 1, 2, 3, 4, 5 };
			Assert::AreEqual(5, list.getLength());
		}

		TEST_METHOD(StressUsageCase1)
		{
			List<int> list;
			int listCounter = 0;

			for (int i = 0; i <= 10000; i++)
			{
				listCounter++;
				list.pushFront(i * -1);
				Assert::AreEqual(i * -1, list.first());
				Assert::AreEqual(listCounter, list.getLength());

				listCounter++;
				list.pushBack(i);
				Assert::AreEqual(i, list.last());
				Assert::AreEqual(listCounter, list.getLength());
			}

			for (int i = 10000; i >= 0; i--)
			{
				Assert::AreEqual(i * -1, list.first());
				Assert::AreEqual(listCounter, list.getLength());
				listCounter--;
				list.popFront();

				Assert::AreEqual(i, list.last());
				Assert::AreEqual(listCounter, list.getLength());
				listCounter--;
				list.popBack();
			}

		}

		TEST_METHOD(StressUsageCase2)
		{
			List<int> list{ 0 };
			

			for (int i = 0; i < 1000; i++)
			{
				Iterator<int> iter = list.begin();

				for (int j = 0; j < list.getLength(); j++)
				{
					if (*iter != list.last())
					{
						iter++;
						Assert::AreEqual(j, *iter);
					}
				}

				list.pushBack(i);

			}

		}
	};
}

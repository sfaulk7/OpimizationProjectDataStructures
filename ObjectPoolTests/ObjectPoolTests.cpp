#include "pch.h"
#include "CppUnitTest.h"
#include "ObjectPool.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ObjectPoolTests
{
	TEST_CLASS(ObjectPoolTests)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			ObjectPool<int> Pool1;
			Assert::IsNotNull(&Pool1);
		}

		TEST_METHOD(AddToPool)
		{
			ObjectPool<int> Pool1;
			Assert::IsNotNull(&Pool1);

			int x = 5;
			Pool1.AddToPool(x, 0);

			//ActiveList should be { 5 }
			//Checks ActiveList
			Assert::AreEqual(1, Pool1.ActiveListCount());
			Assert::AreEqual(0, Pool1.InactiveListCount());

			int y = 7;
			Pool1.AddToPool(y, 0);

			//ActiveList should be { 5, 7 }
			//Checks ActiveList
			Assert::AreEqual(2, Pool1.ActiveListCount());
			Assert::AreEqual(0, Pool1.InactiveListCount());

			int z = 3;
			Pool1.AddToPool(z, 0);

			//ActiveList should be { 3, 5, 7 }
			//Checks ActiveList
			Assert::AreEqual(3, Pool1.ActiveListCount());
			Assert::AreEqual(0, Pool1.InactiveListCount());

			int w = 4;
			Pool1.AddToPool(w, 0);

			//ActiveList should be { 4, 3, 5, 7 }
			//Checks ActiveList
			Assert::AreEqual(4, Pool1.ActiveListCount());
			Assert::AreEqual(0, Pool1.InactiveListCount());
		}

		TEST_METHOD(SetInactive)
		{
			ObjectPool<int> Pool1;
			Assert::IsNotNull(&Pool1);

			int x = 5;
			Pool1.AddToPool(x, 0);

			int y = 7;
			Pool1.AddToPool(y, 0);

			int z = 9;
			Pool1.AddToPool(z, 0);

			//ActivePool should be { 5, 7, 9 }
			Assert::AreEqual(3, Pool1.ActiveListCount());
			Assert::AreEqual(0, Pool1.InactiveListCount());

			Pool1.SetInactive(x);

			//ActivePool should be { 7, 9 }
			//InactivePool should be { 5 }
			Assert::AreEqual(2, Pool1.ActiveListCount());
			Assert::AreEqual(1, Pool1.InactiveListCount());

			Pool1.SetInactive(y);

			//ActivePool should be { 9 }
			//InactivePool should be { 5, 7 }
			Assert::AreEqual(1, Pool1.ActiveListCount());
			Assert::AreEqual(2, Pool1.InactiveListCount());

			Pool1.SetInactive(z);

			//ActivePool should be { }
			//InactivePool should be { 5, 7, 9 }
			Assert::AreEqual(0, Pool1.ActiveListCount());
			Assert::AreEqual(3, Pool1.InactiveListCount());
		}

		TEST_METHOD(Activate)
		{
			ObjectPool<int> Pool1;
			Assert::IsNotNull(&Pool1);

			int x = 5;
			int y = 7;
			int z = 9;
			Pool1.AddToPool(x, 0);
			Pool1.AddToPool(y, 0);
			Pool1.AddToPool(z, 0);

			//ActivePool should be { 5, 7, 9 }
			//InactivePool should be { }
			Assert::AreEqual(3, Pool1.ActiveListCount());
			Assert::AreEqual(0, Pool1.InactiveListCount());

			Pool1.SetInactive(x);
			Pool1.SetInactive(y);
			Pool1.SetInactive(z);

			//ActivePool should be { }
			//InactivePool should be { 5, 7, 9 }
			Assert::AreEqual(0, Pool1.ActiveListCount());
			Assert::AreEqual(3, Pool1.InactiveListCount());

			Pool1.Activate(0);
			//ActivePool should be { 5 }
			//InactivePool should be { 7, 9 }
			Assert::AreEqual(1, Pool1.ActiveListCount());
			Assert::AreEqual(2, Pool1.InactiveListCount());

			Pool1.Activate(1);
			//ActivePool should be { 5, 7 }
			//InactivePool should be { 9 }
			Assert::AreEqual(2, Pool1.ActiveListCount());
			Assert::AreEqual(1, Pool1.InactiveListCount());

			Pool1.Activate(0);
			//ActivePool should be { 9, 5, 7 }
			//InactivePool should be { }
			Assert::AreEqual(3, Pool1.ActiveListCount());
			Assert::AreEqual(0, Pool1.InactiveListCount());
		}

	};
}

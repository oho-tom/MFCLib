#include "stdafx.h"
#include "CppUnitTest.h"
#include "winapi_utility.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace winapi_utility;

namespace UnitTest
{		
	/*!
		@class UT_winapi_utility
		@brief winapi_utilityの単体テストクラス
	*/
	// doxygenにclassを認識させるためTEST_CLASSマクロは使用しない
	//TEST_CLASS(UT_winapi_utility)
	ONLY_USED_AT_NAMESPACE_SCOPE class UT_winapi_utility : public ::Microsoft::VisualStudio::CppUnitTestFramework::TestClass<UT_winapi_utility>
	{
	public:

		/*!
			@brief GetModuleDirectory()
			@par
				内容：取得したディレクトリが存在するか
		*/
		TEST_METHOD(GetModuleDirectory_ResultCheck)
		{
			CString module_directory;
			GetModuleDirectory(module_directory);

			bool result = isExist(module_directory);

			Assert::IsTrue(result);
		}

		/*!
			@brief isExist()
			@par
				内容：存在しないファイルを引数で与える
		*/
		TEST_METHOD(isExist_UnExistFile)
		{
			bool result = isExist(_T("C:\\hoge.txt"));
			Assert::IsFalse(result);
		}

		/*!
			@brief isExist()
			@par
				内容：存在するファイルを引数で与える
		*/
		TEST_METHOD(isExist_ExistFile)
		{
			// モジュールファイルパス
			TCHAR temporary_path[_MAX_PATH];
			memset(temporary_path, 0x00, sizeof(temporary_path));
			int size = ::GetModuleFileName(NULL, temporary_path, sizeof(temporary_path));
			Assert::AreNotEqual(size, 0);

			bool result = isExist(temporary_path);
			Assert::IsTrue(result);
		}

		/*!
			@brief isExist()
			@par
			内容：
				存在しないディレクトリを引数で与える
		*/
		TEST_METHOD(isExist_UnExistDirectory)
		{
			bool result = isExist(_T("C:\\hoge"));
			Assert::IsFalse(result);
		}

		/*!
			@brief isExist()
			@par
				内容：存在するディレクトリを引数で与える
		*/
		TEST_METHOD(isExist_ExistDirectory)
		{
			// モジュールディレクトリ
			CString module_directory;
			GetModuleDirectory(module_directory);

			bool result = isExist(module_directory);
			Assert::IsTrue(result);
		}
	};
}
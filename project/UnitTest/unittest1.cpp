#include "stdafx.h"
#include "CppUnitTest.h"
#include "winapi_utility.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace winapi_utility;

namespace UnitTest
{		
	TEST_CLASS(UT_winapi_utility)
	{
	public:

		/*
		@brief GetModuleDirectory
		@par
			条件：取得したディレクトリが存在するか
		*/
		TEST_METHOD(GetModuleDirectory_ResultCheck)
		{
			CString module_directory;
			GetModuleDirectory(module_directory);

			bool result = isExist(module_directory);

			Assert::AreEqual(result, true);
		}

		/*
		@brief isExist
		@par
			条件：存在しないファイルを引数で与える
		*/
		TEST_METHOD(isExist_UnExistFile)
		{
			bool result = false;

			// モジュールファイルパス
			TCHAR temporary_path[_MAX_PATH];
			memset(temporary_path, 0x00, sizeof(temporary_path));
			::GetModuleFileName(NULL, temporary_path, sizeof(temporary_path));

			// モジュールディレクトリ
			CString module_directory;
			GetModuleDirectory(module_directory);

			// 存在しないファイル
			result = isExist(_T("C:\\hoge.txt"));
			Assert::AreEqual(result, false);
			
			// 存在するファイル
			result = isExist(temporary_path);
			Assert::AreEqual(result, true);

			// 存在しないディレクトリ
			result = isExist(_T("C:\\hoge"));
			Assert::AreEqual(result, false);

			// 存在するディレクトリ
			result = isExist(module_directory);
			Assert::AreEqual(result, true);
		}
	};
}
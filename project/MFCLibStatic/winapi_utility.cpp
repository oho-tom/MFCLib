/*
 @file winapi_utility.cpp
 @brief WindowsAPIユーティリティ関数ヘッダファイル
*/

//------------------------------------------------------------------------------
// include
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "winapi_utility.h"

//------------------------------------------------------------------------------
// メモリリーク検出宣言
//------------------------------------------------------------------------------
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

namespace winapi_utility
{
/*
 @brief モジュールのディレクトリ取得
 @param[out] module_directory モジュールのディレクトリ
 @retval true 成功
 @retval false 失敗
*/
bool GetModuleDirectory(CString& module_directory)
{
	TCHAR temporary_path[_MAX_PATH];
	memset(temporary_path, 0x00, sizeof(temporary_path));
	::GetModuleFileName(NULL, temporary_path, sizeof(temporary_path));
	// 最後の\の位置を求める
	TCHAR* last_backslash = _tcsrchr(temporary_path, '\\');
	// 末尾にNULL文字を入れる
	if (last_backslash != NULL)
		temporary_path[(int)(last_backslash - temporary_path)] = 0x00;

	module_directory = temporary_path;

	return true;
}

bool CreateFolderList(const CString& target_directory, const bool& isIncludingSubDirectory, std::vector<CString>& folder_list)
{
	//----------------------------------------------------------------------
	// 指定フォルダ以下のフォルダリストを取得
	//----------------------------------------------------------------------
	WIN32_FIND_DATA find_data;
	CString target;
	if (target_directory.Right(0) != '\\')
		target = target_directory + _T("\\*");
	else
		target = target_directory + '*';

	HANDLE folder_handle = FindFirstFile(target, &find_data);
	//----------------------------------------------------------------------
	// 取得した一覧の数だけ繰返す
	//----------------------------------------------------------------------
	BOOL isFound = (folder_handle != INVALID_HANDLE_VALUE);
	while (isFound)
	{
		//------------------------------------------------------------------
		// フォルダであるか判定
		//------------------------------------------------------------------
		if (!(find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			// 次の情報へ
			isFound = FindNextFile(folder_handle, &find_data);
			continue;
		}
		CString folder_name(find_data.cFileName);

		//------------------------------------------------------------------
		// 無効なフォルダを除外
		//------------------------------------------------------------------
		if (folder_name == _T(".") || folder_name == _T(".."))
		{
			// 次の情報へ
			isFound = FindNextFile(folder_handle, &find_data);
			continue;
		}

		// 検索用の文字"\\*"を削除
		if (target.Right(0) == '*')
			target.TrimRight();
		if (target.Right(0) == '\\')
			target.TrimRight();

		//------------------------------------------------------------------
		// サブフォルダパス作成
		//------------------------------------------------------------------
		CString sub_folder = target + '\\' + folder_name;
		//------------------------------------------------------------------
		// フォルダパスを出力変数に追加
		//------------------------------------------------------------------
		folder_list.push_back(sub_folder);
		//------------------------------------------------------------------
		// サブフォルダ以下検索
		//------------------------------------------------------------------
		if(isIncludingSubDirectory)
			CreateFolderList(sub_folder, true, folder_list);

		//------------------------------------------------------------------
		// 次の情報へ
		//------------------------------------------------------------------
		isFound = FindNextFile(folder_handle, &find_data);
	}
	//----------------------------------------------------------------------
	// 検索ハンドルクローズ
	//----------------------------------------------------------------------
	FindClose(folder_handle);

	return true;
}

};
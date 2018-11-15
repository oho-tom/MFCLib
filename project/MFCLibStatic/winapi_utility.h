/*
 @file winapi_utility.h
 @brief WindowsAPIユーティリティ関数ヘッダファイル
*/
#ifndef MFCLIB_WINAPI_UTILITY_H_
#define MFCLIB_WINAPI_UTILITY_H_

//------------------------------------------------------------------------------
// include
//------------------------------------------------------------------------------
// MFC header
#include <atlstr.h>
// c++ header
#include <vector>

/*
@namespace winapi_utility
@brief WindowsAPIユーティリティ関数群
*/
namespace winapi_utility
{
//! モジュールのディレクトリ取得
extern bool GetModuleDirectory(CString& module_directory);

//! 指定ディレクトリ配下のフォルダリスト作成
extern bool CreateFolderList(const CString& target_directory, const bool& isIncludingSubDirectory, std::vector<CString>& folder_list);
};
#endif // MFCLIB_WINAPI_UTILITY_H_

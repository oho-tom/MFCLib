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
#include <afxext.h>         // MFC の拡張部分
#include <atlstr.h>
// c++ header
#include <vector>

/*
@namespace winapi_utility
@brief WindowsAPIユーティリティ関数群
*/
namespace winapi_utility
{
//! ファイル/フォルダの存在確認
bool isExist(const CString& path);

//! モジュールのディレクトリ取得
extern bool GetModuleDirectory(CString& module_directory);

//! 指定ディレクトリ配下のフォルダリスト作成
extern bool CreateFolderList(const CString& target_directory, const bool& isIncludingSubDirectory, std::vector<CString>& folder_list);

//! パス文字列を分解する
bool SplitPath(const CString& path, CString& drive, CString& directory, CString& filename, CString& extension);

//! ファイルパスからファイル名に相当する部分を抜き出す
bool GetFileName(const CString& path, CString& filename, const bool hasExtension);

//! CString型文字列から、拡張子に相当する部分を抜き出す
//CString GetExt(const CString& strPathName);

//! CString型文字列から、ドライブ名に相当する部分を抜き出す
//CString GetDrive(const CString& strPathName);

//! CString型文字列から、ファイル名に相当する部分を抜き出す
//CString GetFileName(const CString& strPathName, BOOL bExt);

//! CString型文字列から、ディレクトリパスに相当する部分を抜き出す
//CString GetDirPath(const CString& cstrPath);

};
#endif // MFCLIB_WINAPI_UTILITY_H_

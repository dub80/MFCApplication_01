
// MFCApplication_01.h: основной файл заголовка для приложения MFCApplication_01
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMFCApplication01App:
// Сведения о реализации этого класса: MFCApplication_01.cpp
//

class CMFCApplication01App : public CWinAppEx
{
public:
	CMFCApplication01App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	COleTemplateServer m_server;
		// Объект сервера для создания документа
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication01App theApp;

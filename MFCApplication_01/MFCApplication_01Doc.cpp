
// MFCApplication_01Doc.cpp: реализация класса CMFCApplication01Doc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MFCApplication_01.h"
#endif

#include "MFCApplication_01Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplication01Doc

IMPLEMENT_DYNCREATE(CMFCApplication01Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCApplication01Doc, CDocument)
	ON_COMMAND(ID_FILE_SEND_MAIL, &CMFCApplication01Doc::OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, &CMFCApplication01Doc::OnUpdateFileSendMail)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMFCApplication01Doc, CDocument)
END_DISPATCH_MAP()

// Примечание. Мы добавили поддержку для IID_IMFCApplication_01, чтобы обеспечить безопасную с точки зрения типов привязку
//  из VBA.  Этот IID должен соответствовать GUID, связанному с
//  disp-интерфейсом в файле .IDL.

// {455549b7-d4f3-4ea0-b57c-31a9856acb39}
static const IID IID_IMFCApplication_01 =
{0x455549b7,0xd4f3,0x4ea0,{0xb5,0x7c,0x31,0xa9,0x85,0x6a,0xcb,0x39}};

BEGIN_INTERFACE_MAP(CMFCApplication01Doc, CDocument)
	INTERFACE_PART(CMFCApplication01Doc, IID_IMFCApplication_01, Dispatch)
END_INTERFACE_MAP()


// Создание или уничтожение CMFCApplication01Doc

CMFCApplication01Doc::CMFCApplication01Doc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

	EnableAutomation();

	AfxOleLockApp();
}

CMFCApplication01Doc::~CMFCApplication01Doc()
{
	AfxOleUnlockApp();
}

BOOL CMFCApplication01Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// Сериализация CMFCApplication01Doc

void CMFCApplication01Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CMFCApplication01Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CMFCApplication01Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CMFCApplication01Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CMFCApplication01Doc

#ifdef _DEBUG
void CMFCApplication01Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCApplication01Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CMFCApplication01Doc

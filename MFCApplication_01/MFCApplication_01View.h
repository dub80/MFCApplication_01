
// MFCApplication_01View.h: интерфейс класса CMFCApplication01View
//

#pragma once


class CMFCApplication01View : public CView
{
protected: // создать только из сериализации
	CMFCApplication01View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication01View)

// Атрибуты
public:
	CMFCApplication01Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CMFCApplication01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в MFCApplication_01View.cpp
inline CMFCApplication01Doc* CMFCApplication01View::GetDocument() const
   { return reinterpret_cast<CMFCApplication01Doc*>(m_pDocument); }
#endif


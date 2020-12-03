//---------------------------------------------------------------------------

#ifndef Unit13H
#define Unit13H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <jpeg.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ExtDlgs.hpp>
#include <iostream>
#include<string>

//---------------------------------------------------------------------------
class TForm13 : public TForm
{
__published:	// IDE-managed Components
	TPaintBox *PaintBox1;
	TButton *Button1;
	TOpenPictureDialog *OpenPictureDialog1;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall PaintBox1Paint(TObject *Sender);


private:	// User declarations
public:		// User declarations

int H,W;

TJPEGImage*jpeg;

TColor clSelect;
TColor clColor;
TColor clNewColor;
TColor clPrueba;

TColor *ptr;
TColor *ptr2;

Graphics::TBitmap *pBitmap;// declaracion de matriz
Graphics::TBitmap *pBitmap2;//donde se guardara una copia del pBitmap a modo backup

TRect R1;

	__fastcall TForm13(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm13 *Form13;
//---------------------------------------------------------------------------
#endif

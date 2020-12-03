//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit13.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm13 *Form13;
//---------------------------------------------------------------------------
__fastcall TForm13::TForm13(TComponent* Owner)
	: TForm(Owner)
{
Edit1->Text="";
Edit2->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TForm13::Button1Click(TObject *Sender)
{
pBitmap=new Graphics::TBitmap(); // Reserva de espacio de memoria para TBitmap
pBitmap2=new Graphics::TBitmap();

jpeg=new TJPEGImage;

OpenPictureDialog1->Filter="Archivos graficos|*.bmp;*.jpg;*.jpeg";

	if (OpenPictureDialog1->Execute()) {

		AnsiString ext=ExtractFileExt (OpenPictureDialog1->FileName);

			if (ext==".bmp") {
			pBitmap->LoadFromFile(OpenPictureDialog1->FileName);//ejecucion del cuadro de dialogo dentro de un if para evitar errores
			pBitmap2->LoadFromFile(OpenPictureDialog1->FileName);//ejecucion del cuadro de dialogo dentro de un if para evitar errores
			}
			else{jpeg->LoadFromFile (OpenPictureDialog1->FileName);
			pBitmap->Assign (jpeg);
			pBitmap2->Assign (jpeg);
			delete jpeg;
			}

	pBitmap->PixelFormat=pf32bit;
	pBitmap2->PixelFormat=pf32bit;
	}


//PaintBox1->Height=pBitmap->Height;
//PaintBox1->Width=pBitmap->Width;
R1=PaintBox1->BoundsRect;

int umbral;
int umbral2;


int total=0;
int deforestado=0;
int porcentaje=0;

int total2=0;
int deforestado2=0;
int porcentaje2=0;





umbral=50;
clNewColor=RGB(255,255,255);
umbral2=(clNewColor*umbral)/100;

H=pBitmap->Height;
W=pBitmap->Width;

int red=GetRValue (clNewColor);
int green=GetGValue (clNewColor);
int blue=GetBValue (clNewColor);
clNewColor=RGB(blue,green,red);


for (int y = 0; y < H; y++) {

	ptr=(TColor*) pBitmap->ScanLine[y];

	for (int x = 0; x < W/2; x++) {
		clPrueba=ptr[x];
		total=total+1;

		if ((clPrueba<=(clNewColor+umbral2))&&(clPrueba>=(clNewColor-umbral2))) {

		ptr[x]=clPurple;
		deforestado=deforestado+1;

		}
	}
}
for (int y = 0; y < H; y++) {

	ptr=(TColor*) pBitmap->ScanLine[y];

	for (int x = W/2; x < W; x++) {
		clPrueba=ptr[x];
		total2=total2+1;

		if ((clPrueba<=(clNewColor+umbral2))&&(clPrueba>=(clNewColor-umbral2))) {

		ptr[x]=clPurple;
		deforestado2=deforestado2+1;

		}
	}
}
PaintBox1->Invalidate();

porcentaje=porcentaje+(deforestado*100)/total;
porcentaje2=porcentaje2+(deforestado2*100)/total2;

Edit1->Text=porcentaje;
Edit2->Text=porcentaje2;



}
//---------------------------------------------------------------------------


void __fastcall TForm13::PaintBox1Paint(TObject *Sender)
{
R1=PaintBox1->ClientRect;//Copia el tamaño posiion del paintbox al trect
PaintBox1->Canvas->Brush->Color=clGradientActiveCaption;
PaintBox1->Canvas->Rectangle(R1);
PaintBox1->Canvas->StretchDraw(R1,pBitmap);//grafica archivo -alternativa- PaintBox1->Canvas->Draw(R1.left,R1.top,pBitmap);
}
//---------------------------------------------------------------------------


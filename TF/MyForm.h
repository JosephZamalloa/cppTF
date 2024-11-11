#pragma once
#include "Juego.h"
namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			juego = new Juego();
			jugador = gcnew Bitmap("imagenes\\jugador.png");
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;

	protected:
	private: System::ComponentModel::IContainer^ components;
		   Juego* juego;
		   Bitmap^ jugador;
		   Bitmap^ enemigo;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1262, 810);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = bfc->Allocate(g, this->ClientRectangle);
		juego->Mover(bf->Graphics);
		juego->Mostrar(bf->Graphics, jugador);
		bf->Render(g);

	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		if (e->KeyCode == Keys::Up)
		{
			juego->GetJugador()->setDY(-10);
			juego->GetJugador()->SetAccion(CaminarArriba);
		}
		else if (e->KeyCode == Keys::Down)
		{
			juego->GetJugador()->setDY(10);
			juego->GetJugador()->SetAccion(CaminarAbajo);
		}
		else if (e->KeyCode == Keys::Left)
		{
			juego->GetJugador()->setDX(-10);
			juego->GetJugador()->SetAccion(CaminarIzq);
		}
		else if (e->KeyCode == Keys::Right)
		{
			juego->GetJugador()->setDX(10);
			juego->GetJugador()->SetAccion(CaminarDer);
		}
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Up)
		{
			juego->GetJugador()->setDY(0);
			juego->GetJugador()->SetAccion(CaminarArriba);
		}
		else if (e->KeyCode == Keys::Down)
		{
			juego->GetJugador()->setDY(0);
			juego->GetJugador()->SetAccion(CaminarAbajo);
		}
		else if (e->KeyCode == Keys::Left)
		{
			juego->GetJugador()->setDX(0);
			juego->GetJugador()->SetAccion(CaminarIzq);
		}
		else if (e->KeyCode == Keys::Right)
		{
			juego->GetJugador()->setDX(0);
			juego->GetJugador()->SetAccion(CaminarDer);
		}
	}
	};
}

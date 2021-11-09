#pragma once
#include "Controlador.h"

namespace MawkaGameTF {

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
			srand(time(NULL));
			InitializeComponent();
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			bmpJugador = gcnew Bitmap("jugador.png");
			bmpMapa = gcnew Bitmap("mapa.png");
			bmpEnemigo = gcnew Bitmap("enemigo.png");
			controlador = new Controlador(bmpJugador, bmpEnemigo);
		}

	private:
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ bmpJugador;
		Bitmap^ bmpMapa;
		Bitmap^ bmpEnemigo;
		Controlador* controlador;

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
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ temp;
	protected:

	private: System::Windows::Forms::Timer^ timer2;
	private: System::ComponentModel::IContainer^ components;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->temp = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(0, -2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(832, 434);
			this->panel1->TabIndex = 0;
			// 
			// temp
			// 
			this->temp->Enabled = true;
			this->temp->Tick += gcnew System::EventHandler(this, &MyForm::temp_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(831, 430);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void temp_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::White);
		controlador->colision();
		controlador->moverTodo(buffer->Graphics);
		buffer->Graphics->DrawImage(bmpMapa, 0, 0, panel1->Width, panel1->Height);
		controlador->dibujarTodo(buffer->Graphics, bmpJugador, bmpEnemigo);
		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::A:
			controlador->getJugador()->moverJugador(buffer->Graphics, 'A'); break;

		case Keys::D:
			controlador->getJugador()->moverJugador(buffer->Graphics, 'D'); break;

		case Keys::W:
			controlador->getJugador()->moverJugador(buffer->Graphics, 'W'); break;

		case Keys::S:
			controlador->getJugador()->moverJugador(buffer->Graphics, 'S'); break;
		}
	}
	};
}

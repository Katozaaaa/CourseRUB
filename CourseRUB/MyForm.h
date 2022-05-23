#pragma once

#include "currencies.h"

namespace CourseRUB {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		MyForm(void)
		{
			InitializeComponent();
			this->timer1->Start();
			InitializeEvent();
			InitializeCourse();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ header;

	private: System::Windows::Forms::Button^ exit;
	private: System::Windows::Forms::Button^ roll;

	private: System::Windows::Forms::Label^ course_label;
	private: System::Windows::Forms::Label^ bit_label;



	private: System::Windows::Forms::Panel^ bit_panel;
	private: System::Windows::Forms::Panel^ course_panel;

	private: System::Windows::Forms::Label^ course_EUR;
	private: System::Windows::Forms::Label^ course_USD;
	private: System::Windows::Forms::Label^ course_CHF;
	private: System::Windows::Forms::Label^ course_JPY;
	private: System::Windows::Forms::Label^ course_CNY;
	private: System::Windows::Forms::Label^ course_GBP;

	private: System::Windows::Forms::Label^ bit_CHF;
	private: System::Windows::Forms::Label^ bit_JPY;
	private: System::Windows::Forms::Label^ bit_CNY;
	private: System::Windows::Forms::Label^ bit_GBP;
	private: System::Windows::Forms::Label^ bit_EUR;
	private: System::Windows::Forms::Label^ bit_USD;
	private: System::ComponentModel::IContainer^ components;



	private: Point^ mouseOffset;
	private: System::Windows::Forms::Timer^ timer1;
	private: bool isMouseDown = false;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->header = (gcnew System::Windows::Forms::Panel());
			this->roll = (gcnew System::Windows::Forms::Button());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->course_label = (gcnew System::Windows::Forms::Label());
			this->bit_label = (gcnew System::Windows::Forms::Label());
			this->bit_panel = (gcnew System::Windows::Forms::Panel());
			this->bit_CHF = (gcnew System::Windows::Forms::Label());
			this->bit_JPY = (gcnew System::Windows::Forms::Label());
			this->bit_CNY = (gcnew System::Windows::Forms::Label());
			this->bit_GBP = (gcnew System::Windows::Forms::Label());
			this->bit_EUR = (gcnew System::Windows::Forms::Label());
			this->bit_USD = (gcnew System::Windows::Forms::Label());
			this->course_panel = (gcnew System::Windows::Forms::Panel());
			this->course_CHF = (gcnew System::Windows::Forms::Label());
			this->course_JPY = (gcnew System::Windows::Forms::Label());
			this->course_CNY = (gcnew System::Windows::Forms::Label());
			this->course_GBP = (gcnew System::Windows::Forms::Label());
			this->course_EUR = (gcnew System::Windows::Forms::Label());
			this->course_USD = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->header->SuspendLayout();
			this->bit_panel->SuspendLayout();
			this->course_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// header
			// 
			this->header->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->header->Controls->Add(this->roll);
			this->header->Controls->Add(this->exit);
			this->header->Location = System::Drawing::Point(0, 0);
			this->header->Name = L"header";
			this->header->Size = System::Drawing::Size(273, 30);
			this->header->TabIndex = 0;
			// 
			// roll
			// 
			this->roll->Cursor = System::Windows::Forms::Cursors::Hand;
			this->roll->Location = System::Drawing::Point(202, 5);
			this->roll->Name = L"roll";
			this->roll->Size = System::Drawing::Size(28, 20);
			this->roll->TabIndex = 1;
			this->roll->TabStop = false;
			this->roll->Text = L"—";
			this->roll->UseVisualStyleBackColor = true;
			this->roll->Click += gcnew System::EventHandler(this, &MyForm::roll_Click);
			// 
			// exit
			// 
			this->exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->exit->Location = System::Drawing::Point(236, 5);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(28, 20);
			this->exit->TabIndex = 0;
			this->exit->TabStop = false;
			this->exit->Text = L"X";
			this->exit->UseVisualStyleBackColor = true;
			this->exit->Click += gcnew System::EventHandler(this, &MyForm::exit_Click);
			// 
			// course_label
			// 
			this->course_label->AutoSize = true;
			this->course_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->course_label->ForeColor = System::Drawing::Color::White;
			this->course_label->Location = System::Drawing::Point(8, 15);
			this->course_label->Margin = System::Windows::Forms::Padding(3, 0, 3, 10);
			this->course_label->Name = L"course_label";
			this->course_label->Size = System::Drawing::Size(76, 24);
			this->course_label->TabIndex = 1;
			this->course_label->Text = L"Валюта";
			// 
			// bit_label
			// 
			this->bit_label->AutoSize = true;
			this->bit_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bit_label->ForeColor = System::Drawing::Color::White;
			this->bit_label->Location = System::Drawing::Point(7, 15);
			this->bit_label->Margin = System::Windows::Forms::Padding(3, 10, 3, 10);
			this->bit_label->Name = L"bit_label";
			this->bit_label->Size = System::Drawing::Size(136, 24);
			this->bit_label->TabIndex = 2;
			this->bit_label->Text = L"Предложение";
			// 
			// bit_panel
			// 
			this->bit_panel->Controls->Add(this->bit_CHF);
			this->bit_panel->Controls->Add(this->bit_JPY);
			this->bit_panel->Controls->Add(this->bit_CNY);
			this->bit_panel->Controls->Add(this->bit_GBP);
			this->bit_panel->Controls->Add(this->bit_EUR);
			this->bit_panel->Controls->Add(this->bit_USD);
			this->bit_panel->Controls->Add(this->bit_label);
			this->bit_panel->Location = System::Drawing::Point(110, 36);
			this->bit_panel->Name = L"bit_panel";
			this->bit_panel->Size = System::Drawing::Size(151, 305);
			this->bit_panel->TabIndex = 6;
			// 
			// bit_CHF
			// 
			this->bit_CHF->AutoSize = true;
			this->bit_CHF->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bit_CHF->ForeColor = System::Drawing::Color::White;
			this->bit_CHF->Location = System::Drawing::Point(38, 279);
			this->bit_CHF->Margin = System::Windows::Forms::Padding(3, 10, 3, 10);
			this->bit_CHF->Name = L"bit_CHF";
			this->bit_CHF->Size = System::Drawing::Size(75, 24);
			this->bit_CHF->TabIndex = 13;
			this->bit_CHF->Text = L"00,0000";
			// 
			// bit_JPY
			// 
			this->bit_JPY->AutoSize = true;
			this->bit_JPY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bit_JPY->ForeColor = System::Drawing::Color::White;
			this->bit_JPY->Location = System::Drawing::Point(38, 235);
			this->bit_JPY->Margin = System::Windows::Forms::Padding(3, 10, 3, 10);
			this->bit_JPY->Name = L"bit_JPY";
			this->bit_JPY->Size = System::Drawing::Size(75, 24);
			this->bit_JPY->TabIndex = 12;
			this->bit_JPY->Text = L"00,0000";
			// 
			// bit_CNY
			// 
			this->bit_CNY->AutoSize = true;
			this->bit_CNY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bit_CNY->ForeColor = System::Drawing::Color::White;
			this->bit_CNY->Location = System::Drawing::Point(38, 191);
			this->bit_CNY->Margin = System::Windows::Forms::Padding(3, 10, 3, 10);
			this->bit_CNY->Name = L"bit_CNY";
			this->bit_CNY->Size = System::Drawing::Size(75, 24);
			this->bit_CNY->TabIndex = 11;
			this->bit_CNY->Text = L"00,0000";
			// 
			// bit_GBP
			// 
			this->bit_GBP->AutoSize = true;
			this->bit_GBP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bit_GBP->ForeColor = System::Drawing::Color::White;
			this->bit_GBP->Location = System::Drawing::Point(38, 147);
			this->bit_GBP->Margin = System::Windows::Forms::Padding(3, 10, 3, 10);
			this->bit_GBP->Name = L"bit_GBP";
			this->bit_GBP->Size = System::Drawing::Size(75, 24);
			this->bit_GBP->TabIndex = 10;
			this->bit_GBP->Text = L"00,0000";
			// 
			// bit_EUR
			// 
			this->bit_EUR->AutoSize = true;
			this->bit_EUR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bit_EUR->ForeColor = System::Drawing::Color::White;
			this->bit_EUR->Location = System::Drawing::Point(38, 103);
			this->bit_EUR->Margin = System::Windows::Forms::Padding(3, 10, 3, 10);
			this->bit_EUR->Name = L"bit_EUR";
			this->bit_EUR->Size = System::Drawing::Size(75, 24);
			this->bit_EUR->TabIndex = 9;
			this->bit_EUR->Text = L"00,0000";
			// 
			// bit_USD
			// 
			this->bit_USD->AutoSize = true;
			this->bit_USD->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bit_USD->ForeColor = System::Drawing::Color::White;
			this->bit_USD->Location = System::Drawing::Point(38, 59);
			this->bit_USD->Margin = System::Windows::Forms::Padding(3, 10, 3, 10);
			this->bit_USD->Name = L"bit_USD";
			this->bit_USD->Size = System::Drawing::Size(75, 24);
			this->bit_USD->TabIndex = 8;
			this->bit_USD->Text = L"00,0000";
			// 
			// course_panel
			// 
			this->course_panel->Controls->Add(this->course_CHF);
			this->course_panel->Controls->Add(this->course_JPY);
			this->course_panel->Controls->Add(this->course_CNY);
			this->course_panel->Controls->Add(this->course_GBP);
			this->course_panel->Controls->Add(this->course_EUR);
			this->course_panel->Controls->Add(this->course_USD);
			this->course_panel->Controls->Add(this->course_label);
			this->course_panel->Location = System::Drawing::Point(12, 36);
			this->course_panel->Name = L"course_panel";
			this->course_panel->Size = System::Drawing::Size(92, 305);
			this->course_panel->TabIndex = 7;
			// 
			// course_CHF
			// 
			this->course_CHF->AutoSize = true;
			this->course_CHF->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->course_CHF->ForeColor = System::Drawing::Color::White;
			this->course_CHF->Location = System::Drawing::Point(22, 279);
			this->course_CHF->Margin = System::Windows::Forms::Padding(3, 10, 3, 10);
			this->course_CHF->Name = L"course_CHF";
			this->course_CHF->Size = System::Drawing::Size(49, 24);
			this->course_CHF->TabIndex = 7;
			this->course_CHF->Text = L"CHF";
			// 
			// course_JPY
			// 
			this->course_JPY->AutoSize = true;
			this->course_JPY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->course_JPY->ForeColor = System::Drawing::Color::White;
			this->course_JPY->Location = System::Drawing::Point(22, 235);
			this->course_JPY->Margin = System::Windows::Forms::Padding(3, 10, 3, 10);
			this->course_JPY->Name = L"course_JPY";
			this->course_JPY->Size = System::Drawing::Size(43, 24);
			this->course_JPY->TabIndex = 6;
			this->course_JPY->Text = L"JPY";
			// 
			// course_CNY
			// 
			this->course_CNY->AutoSize = true;
			this->course_CNY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->course_CNY->ForeColor = System::Drawing::Color::White;
			this->course_CNY->Location = System::Drawing::Point(22, 191);
			this->course_CNY->Margin = System::Windows::Forms::Padding(3, 10, 3, 10);
			this->course_CNY->Name = L"course_CNY";
			this->course_CNY->Size = System::Drawing::Size(49, 24);
			this->course_CNY->TabIndex = 5;
			this->course_CNY->Text = L"CNY";
			// 
			// course_GBP
			// 
			this->course_GBP->AutoSize = true;
			this->course_GBP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->course_GBP->ForeColor = System::Drawing::Color::White;
			this->course_GBP->Location = System::Drawing::Point(22, 147);
			this->course_GBP->Margin = System::Windows::Forms::Padding(3, 10, 3, 10);
			this->course_GBP->Name = L"course_GBP";
			this->course_GBP->Size = System::Drawing::Size(48, 24);
			this->course_GBP->TabIndex = 4;
			this->course_GBP->Text = L"GBP";
			// 
			// course_EUR
			// 
			this->course_EUR->AutoSize = true;
			this->course_EUR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->course_EUR->ForeColor = System::Drawing::Color::White;
			this->course_EUR->Location = System::Drawing::Point(22, 103);
			this->course_EUR->Margin = System::Windows::Forms::Padding(3, 10, 3, 10);
			this->course_EUR->Name = L"course_EUR";
			this->course_EUR->Size = System::Drawing::Size(49, 24);
			this->course_EUR->TabIndex = 3;
			this->course_EUR->Text = L"EUR";
			// 
			// course_USD
			// 
			this->course_USD->AutoSize = true;
			this->course_USD->Cursor = System::Windows::Forms::Cursors::Default;
			this->course_USD->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->course_USD->ForeColor = System::Drawing::Color::White;
			this->course_USD->Location = System::Drawing::Point(22, 59);
			this->course_USD->Margin = System::Windows::Forms::Padding(3, 10, 3, 10);
			this->course_USD->Name = L"course_USD";
			this->course_USD->Size = System::Drawing::Size(48, 24);
			this->course_USD->TabIndex = 2;
			this->course_USD->Text = L"USD";
			// 
			// timer1
			// 
			this->timer1->Interval = 600000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->ClientSize = System::Drawing::Size(273, 353);
			this->Controls->Add(this->course_panel);
			this->Controls->Add(this->bit_panel);
			this->Controls->Add(this->header);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->Opacity = 0.97;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->header->ResumeLayout(false);
			this->bit_panel->ResumeLayout(false);
			this->bit_panel->PerformLayout();
			this->course_panel->ResumeLayout(false);
			this->course_panel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		void InitializeCourse(void)
		{
				Currencies curr;
				this->bit_USD->Text = gcnew System::String(curr.getCurr("USD/RUB").c_str());
				this->bit_EUR->Text = gcnew System::String(curr.getCurr("EUR/RUB").c_str());
				this->bit_GBP->Text = gcnew System::String(curr.getCurr("GBP/RUB").c_str());
				this->bit_CNY->Text = gcnew System::String(curr.getCurr("CNY/RUB").c_str());
				this->bit_JPY->Text = gcnew System::String(curr.getCurr("JPY/RUB").c_str());
				this->bit_CHF->Text = gcnew System::String(curr.getCurr("CHF/RUB").c_str());
		}

		void InitializeEvent(void)
		{
			this->header->MouseDown += gcnew MouseEventHandler(this, &MyForm::MouseDownF);
			this->header->MouseMove += gcnew MouseEventHandler(this, &MyForm::MouseMoveF);
			this->header->MouseUp += gcnew MouseEventHandler(this, &MyForm::MouseUpF);
		}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		InitializeCourse();
	}

	private: System::Void exit_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Environment::Exit(0);
	}

	private: System::Void roll_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->WindowState = FormWindowState::Minimized;
	}

	private: System::Void MouseDownF(System::Object^ sender, MouseEventArgs^ e)
	{
		int xOffset;
		int yOffset;

		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			xOffset = -(e->X) - SystemInformation::FrameBorderSize.Width;
			yOffset = -(e->Y) - SystemInformation::CaptionHeight - SystemInformation::FrameBorderSize.Height;
			this->mouseOffset = gcnew Point(xOffset, yOffset);
			isMouseDown = true;
		}
	}

	private: System::Void MouseMoveF(System::Object^ sender, MouseEventArgs^ e)
	{
		if (isMouseDown)
		{
			Point mousePos = Control::MousePosition;
			mousePos.Offset(mouseOffset->X, mouseOffset->Y);
			this->Location = mousePos;
		}
	}

	private: System::Void MouseUpF(System::Object^ sender, MouseEventArgs^ e)
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			isMouseDown = false;
		}
	}
};
}

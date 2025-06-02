#pragma once

namespace Lab08 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Drawing::Drawing2D;
	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public enum class ShapeType { Point, Line, Rectangle, Ellipse };

	public ref struct Shape
	{
		ShapeType Type;
		Point Start, End;
		Color FillColor;
		bool Filled;

		Shape(ShapeType type, Point start, Point end, Color color, bool filled)
			: Type(type), Start(start), End(end), FillColor(color), Filled(filled) {}
	};

	public ref class MainForm : public Form
	{
	public:
		MainForm()
		{
			InitializeComponent();
			shapes = gcnew List<Shape^>(109); 
			rubberLine = gcnew List<Point>();
			this->DoubleBuffered = true;
			UpdateTitle();
		}

	protected:
		~MainForm()
		{
			if (components) delete components;
		}

	private:
		MenuStrip^ menuStrip1;
		ToolStripMenuItem^ FileToolStripMenuItem;
		ToolStripMenuItem^ ObjectsToolStripMenuItem;
		ToolStripMenuItem^ DotToolStripMenuItem;
		ToolStripMenuItem^ LineToolStripMenuItem;
		ToolStripMenuItem^ QuadToolStripMenuItem;
		ToolStripMenuItem^ ElipseToolStripMenuItem;
		ToolStripMenuItem^ HelpToolStripMenuItem;
		System::ComponentModel::Container^ components;


		List<Shape^>^ shapes;
		List<Point>^ rubberLine;
		ShapeType currentShape = ShapeType::Point;
		bool drawing = false;
		Point inputStart, inputEnd;

	
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew MenuStrip());
			this->FileToolStripMenuItem = (gcnew ToolStripMenuItem(L"Файл"));
			this->ObjectsToolStripMenuItem = (gcnew ToolStripMenuItem(L"Об’єкти"));
			this->DotToolStripMenuItem = (gcnew ToolStripMenuItem(L"Точка"));
			this->LineToolStripMenuItem = (gcnew ToolStripMenuItem(L"Лінія"));
			this->QuadToolStripMenuItem = (gcnew ToolStripMenuItem(L"Прямокутник"));
			this->ElipseToolStripMenuItem = (gcnew ToolStripMenuItem(L"Еліпс"));
			this->HelpToolStripMenuItem = (gcnew ToolStripMenuItem(L"Довідка"));


			this->ObjectsToolStripMenuItem->DropDownItems->AddRange(
				gcnew cli::array<ToolStripItem^> {
				DotToolStripMenuItem, LineToolStripMenuItem, QuadToolStripMenuItem, ElipseToolStripMenuItem
			});

			this->menuStrip1->Items->AddRange(
				gcnew cli::array<ToolStripItem^> {
				FileToolStripMenuItem,
					ObjectsToolStripMenuItem,
					HelpToolStripMenuItem
			});

	
			this->DotToolStripMenuItem->Click += gcnew EventHandler(this, &MainForm::Dot_Click);
			this->LineToolStripMenuItem->Click += gcnew EventHandler(this, &MainForm::Line_Click);
			this->QuadToolStripMenuItem->Click += gcnew EventHandler(this, &MainForm::Quad_Click);
			this->ElipseToolStripMenuItem->Click += gcnew EventHandler(this, &MainForm::Elipse_Click);


			this->MainMenuStrip = this->menuStrip1;
			this->Controls->Add(this->menuStrip1);
			this->Text = L"Lab8: Graphics Editor";
			this->Width = 900; this->Height = 600;
			this->menuStrip1->Dock = DockStyle::Top;

			this->MouseDown += gcnew MouseEventHandler(this, &MainForm::MainForm_MouseDown);
			this->MouseMove += gcnew MouseEventHandler(this, &MainForm::MainForm_MouseMove);
			this->MouseUp += gcnew MouseEventHandler(this, &MainForm::MainForm_MouseUp);
			this->Paint += gcnew PaintEventHandler(this, &MainForm::MainForm_Paint);
		}

	
		Color GetEllipseFillColor() {
			return Color::FromArgb(173, 216, 230); 
		}


		void UpdateTitle() {
			array<String^>^ names = { L"Dot", L"Line", L"Quad", L"Elipse" };
			this->Text = "Lab8 — " + names[(int)currentShape];
		}


		void Dot_Click(Object^, EventArgs^) { currentShape = ShapeType::Point;      UpdateTitle(); }
		void Line_Click(Object^, EventArgs^) { currentShape = ShapeType::Line;       UpdateTitle(); }
		void Quad_Click(Object^, EventArgs^) { currentShape = ShapeType::Rectangle;   UpdateTitle(); }
		void Elipse_Click(Object^, EventArgs^) { currentShape = ShapeType::Ellipse;    UpdateTitle(); }


		void MainForm_MouseDown(Object^, MouseEventArgs^ e)
		{
			inputStart = inputEnd = e->Location;
			drawing = true;
			if (currentShape == ShapeType::Line)
				rubberLine->Clear();
		}

		void MainForm_MouseMove(Object^, MouseEventArgs^ e)
		{
			if (!drawing) return;
			inputEnd = e->Location;
			if (currentShape == ShapeType::Line)
				rubberLine->Add(inputEnd);
			this->Invalidate();
		}

		void MainForm_MouseUp(Object^, MouseEventArgs^ e)
		{
			if (!drawing) return;
			inputEnd = e->Location;


			if (currentShape == ShapeType::Point) {
				shapes->Add(gcnew Shape(ShapeType::Point, inputEnd, inputEnd, Color::Black, false));
			}
			else if (currentShape == ShapeType::Line) {
				for (int i = 1; i < rubberLine->Count; ++i)
					shapes->Add(gcnew Shape(ShapeType::Line, rubberLine[i - 1], rubberLine[i], Color::Red, false));
				rubberLine->Clear();
			}
			else if (currentShape == ShapeType::Rectangle) {
				shapes->Add(gcnew Shape(ShapeType::Rectangle, inputStart, inputEnd, Color::White, false));
			}
			else if (currentShape == ShapeType::Ellipse) {
				shapes->Add(gcnew Shape(ShapeType::Ellipse, inputStart, inputEnd, GetEllipseFillColor(), true));
			}
			drawing = false;
			this->Invalidate();
		}


		void MainForm_Paint(Object^, PaintEventArgs^ e)
		{
			Graphics^ g = e->Graphics;

			for each (Shape ^ shape in shapes) {
				DrawShape(g, shape);
			}

			if (drawing && currentShape == ShapeType::Line && rubberLine->Count > 1) {
				Pen^ pen = gcnew Pen(Color::Red, 2);
				for (int i = 1; i < rubberLine->Count; ++i)
					g->DrawLine(pen, rubberLine[i - 1], rubberLine[i]);
				delete pen;
			}

			if (drawing && (currentShape == ShapeType::Rectangle || currentShape == ShapeType::Ellipse)) {
				Pen^ pen = gcnew Pen(Color::Gray, 2);
				Rectangle rect = GetRect(inputStart, inputEnd);

				if (currentShape == ShapeType::Rectangle) {
					g->DrawRectangle(pen, rect);
				}
				else if (currentShape == ShapeType::Ellipse) {
					g->DrawEllipse(pen, rect);
				}
				delete pen;
			}
		}

	
		void DrawShape(Graphics^ g, Shape^ shape)
		{
			Pen^ blackPen = gcnew Pen(Color::Black, 2);
			Pen^ redPen = gcnew Pen(Color::Red, 2);

			switch (shape->Type) {
			case ShapeType::Point:
				g->FillEllipse(Brushes::Black, shape->Start.X - 2, shape->Start.Y - 2, 4, 4);
				break;
			case ShapeType::Line:
				g->DrawLine(redPen, shape->Start, shape->End);
				break;
			case ShapeType::Rectangle:
				if (shape->Filled)
					g->FillRectangle(gcnew SolidBrush(shape->FillColor), GetRect(shape->Start, shape->End));
				g->DrawRectangle(blackPen, GetRect(shape->Start, shape->End));
				break;
			case ShapeType::Ellipse:
				if (shape->Filled)
					g->FillEllipse(gcnew SolidBrush(shape->FillColor), GetRect(shape->Start, shape->End));
				g->DrawEllipse(blackPen, GetRect(shape->Start, shape->End));
				break;
			}
			delete blackPen;
			delete redPen;
		}

		Rectangle GetRect(Point a, Point b) {
			int x = Math::Min(a.X, b.X);
			int y = Math::Min(a.Y, b.Y);
			int w = Math::Abs(a.X - b.X);
			int h = Math::Abs(a.Y - b.Y);
			return Rectangle(x, y, w, h);
		}
	};

}

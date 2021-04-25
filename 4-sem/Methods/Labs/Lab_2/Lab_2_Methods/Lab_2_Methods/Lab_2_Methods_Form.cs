using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MathNet.Numerics;
using MathNet.Numerics.LinearAlgebra;

namespace Lab_2_Methods
{
    public partial class Lab_2_Methods_Form : Form
    {
        public MyInput input;
        public Lab_2_Methods_Form()
        {
            InitializeComponent();
            input = new MyInput();
            gr = pictureBox1.CreateGraphics();
            gr.Clear(Color.DarkGray);
        }
        Graphics gr;
        private void button1_Click(object sender, EventArgs e)
        {
            gr.Clear(Color.DarkGray);
            input.AddPoints(textBox_X.Text, textBox_Y.Text);

            input.BuildLagranjePolynome();
            label1.Text = "Lagranje = " + input.OutputLagranje();

            input.BuildNewtonPolynome();
            label2.Text = "Newton = " + input.OutputNewton();


            DrawMethods();
        }
        void DrawMethods()
        {

            PointF buf = new PointF(0 + 50, (float)input.LagranjePoint(0 + 50, 3).Item2 * 10);
            Pen pen = new Pen(Color.Red, 6);
            List<PointF> points = new List<PointF>();
            gr.DrawLine(new Pen(Color.Gray, 2), ToMap(new PointF(-500, 0)), ToMap(new PointF(500, 0)));
            gr.DrawLine(new Pen(Color.Gray, 2), ToMap(new PointF(0, 550)), ToMap(new PointF(0, -500)));
            for (double i = -2; i < 10; i += 0.1)
            {
                points.Add(new PointF((float)i, -(float)input.LagranjePoint(i, 3).Item2));
                //gr.DrawEllipse(pen, new RectangleF((float)i*30+250, -(float)input.LagranjePoint(i, 3).Item2*30+250, 1, 1));
            }
            for (int i = 0; i < points.Count - 1; i++)
            {
                gr.DrawLine(pen, ToMap(points[i]), ToMap(points[i + 1]));
                //gr.DrawEllipse(pen, new RectangleF((float)i*30+250, -(float)input.LagranjePoint(i, 3).Item2*30+250, 1, 1));
            }

            Random rnd = new Random();
            label3.Text = "";
            for (int k = 1; k < input.x_input.Length; k++)
            {
                pen = new Pen(Color.FromArgb(0,0,200), 2);
                input.BuildDivSquarePolynome(k);
                points.Clear();
                for (double i = -2; i < 10; i += 0.1)
                {
                    points.Add(new PointF((float)i, -(float)input.DivSquarePoint(i, 3).Item2));
                    //gr.DrawEllipse(pen, new RectangleF((float)i*30+250, -(float)input.LagranjePoint(i, 3).Item2*30+250, 1, 1));
                }
                for (int i = 0; i < points.Count - 1; i++)
                {
                    gr.DrawLine(pen, ToMap(points[i]), ToMap(points[i + 1]));
                    //gr.DrawEllipse(pen, new RectangleF((float)i*30+250, -(float)input.LagranjePoint(i, 3).Item2*30+250, 1, 1));
                }
                label3.Text += "Div_Square(" + k + ") " + input.OutputDivSquare() + "\n";
            }
           
            for (int i = 0; i < input.x_input.Length; i++)
            {
                gr.FillEllipse(new SolidBrush(Color.Aquamarine), new RectangleF(new PointF(ToMap(new PointF(input.x_input[i], -input.y_input[i])).X-5, ToMap(new PointF(input.x_input[i], -input.y_input[i])).Y-5), new SizeF(10, 10)));
                //gr.DrawLine(new Pen(Color.Aquamarine, 6), ToMap(new PointF(input.x_input[i], -input.y_input[i])), ToMap(new PointF(input.x_input[i]+0.1f, -input.y_input[i]+0.1f)));
            }

        }
        PointF ToMap(PointF point)
        {
            point.X *= 60;
            point.Y *= 60;
            point.X += 250 + trackBar1.Value;
            point.Y += 250 + trackBar2.Value;
            return point;
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            gr.Clear(Color.DarkGray);
            DrawMethods();
        }

        private void trackBar2_Scroll(object sender, EventArgs e)
        {
            gr.Clear(Color.DarkGray);
            DrawMethods();
        }
    }
}

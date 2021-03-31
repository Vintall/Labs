using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Methods_Lab_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public class InputData
        {
            double a, b, accuracy;
            int[] func_0;
            int[] func_1;
            int[] func_2;
            public InputData(string f, double a, double b, double acc)
            {
                string []f_mod = f.Split(';');

                func_0 = new int[f_mod.Length];
                for (int i = 0; i < f_mod.Length; i++)
                    func_0[i] = int.Parse(f_mod[i]);

                func_1 = new int[func_0.Length-1];
                for (int i = 0; i < func_1.Length; i++)
                    func_1[i] = func_0[i] * (func_1.Length - i);

                func_2 = new int[func_1.Length-1];
                for (int i = 0; i < func_2.Length; i++)
                    func_2[i] = func_1[i] * (func_2.Length - i);

                this.a = a;
                this.b = b;
                accuracy = 1 / Math.Pow(10, acc);
            }
            double Func0(double x)
            {
                double res = 0;
                for (int i = 0; i < func_0.Length; i++)
                    res += func_0[i] * Math.Pow(x, func_0.Length - i - 1);
                return res;
            }
            double Func1(double x)
            {
                double res = 0;
                for (int i = 0; i < func_1.Length; i++)
                    res += func_1[i] * Math.Pow(x, func_1.Length - i - 1);
                return res;
            }
            double Func2(double x)
            {
                double res = 0;
                for (int i = 0; i < func_2.Length; i++)
                    res += func_2[i] * Math.Pow(x, func_2.Length - i - 1);
                return res;
            }
            public (int, double) Half()
            {
                double a, b, x;
                int n = 0;
                a = this.a;
                b = this.b;
                x = a;
                while (Math.Abs(b - a) > 2 * accuracy && Func0(x) != 0) 
                {
                    if (Func0(a) * Func0(x) < 0)
                    {
                        b = x;
                        x = (a + b) / 2;
                    }
                    else
                    {
                        a = x;
                        x = (a + b) / 2;
                    }
                    n++;
                }
                return (n, x);
            }
            public (int, double) Iter()
            {
                double x, a, b, k, min, max, t;
                int n = 0;
                a = this.a;
                b = this.b;
                x = a;
                min = Func1(a);
                t = Func1(b);

                if (t < min)
                {
                    max = min;
                    min = t;
                }
                else 
                    max = t;

                k = 2 / (Math.Abs(min) + Math.Abs(max));
                if (t < 0) 
                    k *= -1;

                while (Math.Abs(Func0(x)) / Math.Abs(Func0(min)) > accuracy)
                {
                    x -= k * Func0(x);
                    n++;
                }
                return (n, x);
            }
            public (int, double) Newton()
            {
                double x, a, b, min, max, t;
                int n = 0;
                a = this.a;
                b = this.b;

                if (Func0(a) * Func0(a) > 0)
                    x = a;
                else x = b;
                min = Func1(a);
                t = Func1(b);
                if (t < min)
                {
                    max = min;
                    min = t;
                }
                else 
                    max = t;

                while (Math.Abs(Func0(x)) / Math.Abs(Func0(min)) > accuracy)
                {
                    x = x - Func0(x) / Func1(x);
                    n++;
                }
                return (n, x);
            }
            public (int, double) Chord()
            {
                double x, a, b, min, max, t, c;
                int n = 0;
                a = this.a;
                b = this.b;

                if (Func0(a) * Func2(a) > 0)
                {
                    c = a;
                    x = b;
                }
                else
                {
                    c = b;
                    x = a;
                }

                min = Func1(a);
                t = Func1(b);

                if (t < min)
                {
                    max = min;
                    min = t;
                }
                else 
                    max = t;

                while (Math.Abs(Func0(x)) / Math.Abs(min) > accuracy)
                {
                    x = x - ((x - c) * Func0(x)) / (Func0(x) - Func0(c));
                    n++;
                }
                return (n, x);
            }
            public (int, double) Combined()
            {
                double x1 = a, x2 = b, x = a, min, max, t;
                int n = 0;
                min = Func1(a);
                t = Func1(b);
                if (t < min)
                {
                    max = min;
                    min = t;
                }
                else max = t;
                if (Func1(a) * Func2(a) > 0)
                {
                    while (Math.Abs(Func0(x)) / Math.Abs(min) > accuracy)
                    {
                        x1 = x1 - ((x2 - x1) * Func0(x1)) / (Func0(x2) - Func0(x1));
                        x2 = x2 - Func0(x2) / Func1(x2);
                        x = (x1 + x2) / 2;
                        n++;
                    }
                }
                else
                {
                    while (Math.Abs(Func0(x)) / Math.Abs(min) > accuracy)
                    {
                        x2 = x2 - ((x2 - x1) * Func0(x2)) / (Func0(x2) - Func0(x1));
                        x1 = x1 - Func0(x1) / Func1(x1);
                        x = (x1 + x2) / 2;
                        n++;
                    }
                }
                double res = (x1 + x2) / 2;
                return (n, res);
            }
        }
        InputData input;
        private void button1_Click(object sender, EventArgs e)
        {
            input = new InputData(textBox_func.Text, double.Parse(textBox_a.Text), double.Parse(textBox_b.Text), double.Parse(textBox_accuracy.Text));
            (int, double) res = input.Half();
            label_half_1.Text = "Кол-во итераций = " + res.Item1.ToString();
            label_half_2.Text = "Корень = " + res.Item2.ToString();

            res = input.Iter();
            label_iteration_1.Text = "Кол-во итераций = " + res.Item1.ToString();
            label_iteration_2.Text = "Корень = " + res.Item2.ToString();

            res = input.Newton();
            label_newton_1.Text = "Кол-во итераций = " + res.Item1.ToString();
            label_newton_2.Text = "Корень = " + res.Item2.ToString();

            res = input.Chord();
            label_chord_1.Text = "Кол-во итераций = " + res.Item1.ToString();
            label_chord_2.Text = "Корень = " + res.Item2.ToString();

            res = input.Combined();
            label_combine_1.Text = "Кол-во итераций = " + res.Item1.ToString();
            label_combine_2.Text = "Корень = " + res.Item2.ToString();
        }


    }
}

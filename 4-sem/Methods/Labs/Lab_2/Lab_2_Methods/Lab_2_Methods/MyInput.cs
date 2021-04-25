using System;
using System.Collections.Generic;
using System.Text;
using MathNet.Numerics.LinearAlgebra;
using MathNet.Numerics;
using MathNet.Numerics.Differentiation;

namespace Lab_2_Methods
{
    public class MyInput
    {
        public int[] x_input;
        public int[] y_input;
        public Polynomial lagranje;
        public Polynomial newton;
        public Polynomial div_square;
        public struct P_R
        {
            public double[] podil_rizn;
        }
        public P_R[] pod_r;
        
        public MyInput()
        {
            
        }
        public void AddPoints(string x, string y)
        {
            string[] splitted = x.Split(' ');
            x_input = new int[splitted.Length];
            for (int i = 0; i < splitted.Length; i++)
                x_input[i] = int.Parse(splitted[i]);

            splitted = y.Split(' ');
            y_input = new int[splitted.Length];
            for (int i = 0; i < splitted.Length; i++)
                y_input[i] = int.Parse(splitted[i]);
        }
        public void BuildLagranjePolynome()
        {
            lagranje = new Polynomial(0, 0);
            for (int i = 0; i < x_input.Length; i++)
            {
                Polynomial buf = new Polynomial(1, 0);
                buf *= y_input[i];
                for (int j = 0; j < x_input.Length; j++)
                {
                    if (j == i) 
                        continue;

                    buf *= new Polynomial(-x_input[j], 1);
                    buf /= (x_input[i] - x_input[j]);
                }
                lagranje += buf;
            }
        }
        public void BuildNewtonPolynome()
        {
            pod_r = new P_R[x_input.Length - 1];
            int lader_count = x_input.Length - 1;
            for (int i = 0; i < pod_r.Length; i++)
            {
                pod_r[i].podil_rizn = new double[lader_count];
                lader_count--;
            }
            for (int i = 0; i < pod_r.Length; i++)
            {
                if (i == 0)
                {
                    for (int j = 0; j < pod_r[0].podil_rizn.Length; j++)
                    {
                        pod_r[0].podil_rizn[j] = ((double)y_input[j + 1] - y_input[j]) / ((double)x_input[j+1] - x_input[j]);
                    }
                }
                else
                {
                    for (int j = 0; j < pod_r[i].podil_rizn.Length; j++)
                    {
                        pod_r[i].podil_rizn[j] = (pod_r[i-1].podil_rizn[j + 1] - pod_r[i-1].podil_rizn[j]) / ((double)x_input[j + 1 + i] - x_input[j]);
                    }
                }
            }
            newton = new Polynomial(0, 0);
            Polynomial buf = new Polynomial(0, 0);
            Polynomial buf2;
            newton += y_input[0];
            for (int i = 0; i < x_input.Length - 1; i++)
            {
                buf = new Polynomial(1, 0);

                for (int j = 0; j <= i; j++)
                {
                    buf2 = new Polynomial(-x_input[j], 1);
                    buf *= buf2;
                }
                
                buf *= pod_r[i].podil_rizn[0];
                newton += buf;
            }
        }
        //public double[,] slar;
        public void BuildDivSquarePolynome(int power)
        {
            //Polynomial line;
            double[,] slar = new double[power+1, power+1];
            double[] right_part = new double[power + 1];
            double[] koef = new double[power + 1];
            
            for (int i = 0; i < power+1; i++)
            {
                for (int j = 0; j < power + 1; j++)
                {
                    double sum = 0;
                    for (int k = 0; k < x_input.Length; k++)
                    {
                        sum += Math.Pow(x_input[k], power + i - j);
                    }
                    slar[i, j] = sum;
                }
            }
            for (int i = 0; i < power + 1; i++)
            {
                double sum = 0;
                for (int k = 0; k < x_input.Length; k++)
                {
                    sum += y_input[k]*Math.Pow(x_input[k], i);
                }
                right_part[i] = sum;
            }


            Matrix<double> slar_matrix = Matrix<double>.Build.DenseOfArray(slar);
            double determinant = slar_matrix.Determinant();
            double[,] buf_slar = new double[power + 1, power + 1];
            for (int i = 0; i < power + 1; i++)
            {
                for (int b = 0; b < power + 1; b++)
                    for (int g = 0; g < power + 1; g++)
                    {
                        buf_slar[b, g] = slar[b, g];
                    }
                
                for (int j = 0; j < power + 1; j++)
                {
                    buf_slar[j, i] = right_part[j];
                }
                Matrix<double> koef_find = Matrix<double>.Build.DenseOfArray(buf_slar);
                koef[i] = koef_find.Determinant() / determinant;
            }
            double[] koef_buf = new double[koef.Length];
            for (int i = 0; i < koef.Length; i++)
            {
                koef_buf[i] = koef[koef.Length - i - 1];
            }
            div_square = new Polynomial(koef_buf);
        }
        public string OutputNewton()
        {
            string output = "";
            Polynomial out_p = newton.Clone();
            for (int i = 0; i < out_p.Coefficients.Length; i++)
                out_p.Coefficients[i] = Math.Round(out_p.Coefficients[i], 2);
            output = out_p.ToStringDescending();
            return output;
        }
        public string OutputLagranje()
        {
            string output = "";
            Polynomial out_p = lagranje.Clone();
            for (int i = 0; i < out_p.Coefficients.Length; i++)
                out_p.Coefficients[i] = Math.Round(out_p.Coefficients[i], 2);
            output = out_p.ToStringDescending();
            return output;
        }
        public string OutputDivSquare()
        {
            string output = "";
            Polynomial out_p = div_square.Clone();
            for (int i = 0; i < out_p.Coefficients.Length; i++)
                out_p.Coefficients[i] = Math.Round(out_p.Coefficients[i], 2);
            output = out_p.ToStringDescending();
            return output;
        }
        public (double, double) LagranjePoint(double x, int accuracy)
        {
            return (x, Math.Round(lagranje.Evaluate(x), accuracy));
        }
        public (double, double) NewtonPoint(double x, int accuracy)
        {
            return (x, Math.Round(newton.Evaluate(x), accuracy));
        }
        public (double, double) DivSquarePoint(double x, int accuracy)
        {
            return (x, Math.Round(div_square.Evaluate(x), accuracy));
        }
    }
}

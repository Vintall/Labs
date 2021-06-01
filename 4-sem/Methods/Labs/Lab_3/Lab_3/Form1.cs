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
using MathNet.Numerics.Integration;
using MathNet.Numerics.IntegralTransforms;
using MathNet.Numerics.LinearAlgebra;
using MathNet.Symbolics;

namespace Lab_3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            Function e = Function.Exp;
            
            label1.Text =  e.ToString();
            //SimpsonRule.IntegrateComposite(x=>,)
        }
        class MyLab
        {
            public MyLab()
            {

            }
            public void Method_1()
            {
                
                
            }
            public void Method_2()
            {

            }
        }

    }
}

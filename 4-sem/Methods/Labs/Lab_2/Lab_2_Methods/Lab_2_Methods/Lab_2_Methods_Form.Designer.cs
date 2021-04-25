
namespace Lab_2_Methods
{
    partial class Lab_2_Methods_Form
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.textBox_X = new System.Windows.Forms.TextBox();
            this.textBox_Y = new System.Windows.Forms.TextBox();
            this.label_X = new System.Windows.Forms.Label();
            this.label_Y = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.trackBar1 = new System.Windows.Forms.TrackBar();
            this.trackBar2 = new System.Windows.Forms.TrackBar();
            this.label3 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar2)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label1.Location = new System.Drawing.Point(12, 365);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(85, 25);
            this.label1.TabIndex = 0;
            this.label1.Text = "Lagranje";
            // 
            // textBox_X
            // 
            this.textBox_X.Location = new System.Drawing.Point(51, 14);
            this.textBox_X.Name = "textBox_X";
            this.textBox_X.Size = new System.Drawing.Size(100, 23);
            this.textBox_X.TabIndex = 1;
            this.textBox_X.Text = "0 1 3 4 5";
            // 
            // textBox_Y
            // 
            this.textBox_Y.Location = new System.Drawing.Point(51, 41);
            this.textBox_Y.Name = "textBox_Y";
            this.textBox_Y.Size = new System.Drawing.Size(100, 23);
            this.textBox_Y.TabIndex = 2;
            this.textBox_Y.Text = "2 -1 0 1 2";
            // 
            // label_X
            // 
            this.label_X.AutoSize = true;
            this.label_X.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label_X.Location = new System.Drawing.Point(22, 12);
            this.label_X.Name = "label_X";
            this.label_X.Size = new System.Drawing.Size(23, 25);
            this.label_X.TabIndex = 3;
            this.label_X.Text = "X";
            // 
            // label_Y
            // 
            this.label_Y.AutoSize = true;
            this.label_Y.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label_Y.Location = new System.Drawing.Point(22, 41);
            this.label_Y.Name = "label_Y";
            this.label_Y.Size = new System.Drawing.Size(23, 25);
            this.label_Y.TabIndex = 4;
            this.label_Y.Text = "Y";
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.button1.Location = new System.Drawing.Point(32, 70);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(140, 36);
            this.button1.TabIndex = 5;
            this.button1.Text = "Задать точки";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.SystemColors.Control;
            this.label2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.label2.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label2.Location = new System.Drawing.Point(12, 403);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(78, 25);
            this.label2.TabIndex = 6;
            this.label2.Text = "Newton";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(189, 0);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(500, 357);
            this.pictureBox1.TabIndex = 7;
            this.pictureBox1.TabStop = false;
            // 
            // trackBar1
            // 
            this.trackBar1.Location = new System.Drawing.Point(3, 112);
            this.trackBar1.Maximum = 500;
            this.trackBar1.Minimum = -500;
            this.trackBar1.Name = "trackBar1";
            this.trackBar1.Size = new System.Drawing.Size(180, 45);
            this.trackBar1.TabIndex = 8;
            this.trackBar1.Scroll += new System.EventHandler(this.trackBar1_Scroll);
            // 
            // trackBar2
            // 
            this.trackBar2.Location = new System.Drawing.Point(3, 163);
            this.trackBar2.Maximum = 500;
            this.trackBar2.Minimum = -500;
            this.trackBar2.Name = "trackBar2";
            this.trackBar2.Size = new System.Drawing.Size(180, 45);
            this.trackBar2.TabIndex = 9;
            this.trackBar2.Scroll += new System.EventHandler(this.trackBar2_Scroll);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.SystemColors.Control;
            this.label3.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.label3.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label3.Location = new System.Drawing.Point(12, 437);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(98, 25);
            this.label3.TabIndex = 10;
            this.label3.Text = "DivSquare";
            // 
            // Lab_2_Methods_Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(690, 660);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.trackBar2);
            this.Controls.Add(this.trackBar1);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label_Y);
            this.Controls.Add(this.label_X);
            this.Controls.Add(this.textBox_Y);
            this.Controls.Add(this.textBox_X);
            this.Controls.Add(this.label1);
            this.Name = "Lab_2_Methods_Form";
            this.Text = "Lab_2_Ilyashenko";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBox_X;
        private System.Windows.Forms.TextBox textBox_Y;
        private System.Windows.Forms.Label label_X;
        private System.Windows.Forms.Label label_Y;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.TrackBar trackBar1;
        private System.Windows.Forms.TrackBar trackBar2;
        private System.Windows.Forms.Label label3;
    }
}


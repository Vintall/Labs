
namespace Methods_Lab_1
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.a_limit = new System.Windows.Forms.Label();
            this.b_limit = new System.Windows.Forms.Label();
            this.textBox_a = new System.Windows.Forms.TextBox();
            this.textBox_b = new System.Windows.Forms.TextBox();
            this.textBox_accuracy = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.lable_accuracy = new System.Windows.Forms.Label();
            this.iteration_group = new System.Windows.Forms.GroupBox();
            this.label_iteration_2 = new System.Windows.Forms.Label();
            this.label_iteration_1 = new System.Windows.Forms.Label();
            this.chord_group = new System.Windows.Forms.GroupBox();
            this.label_chord_2 = new System.Windows.Forms.Label();
            this.label_chord_1 = new System.Windows.Forms.Label();
            this.newton_group = new System.Windows.Forms.GroupBox();
            this.label_newton_2 = new System.Windows.Forms.Label();
            this.label_newton_1 = new System.Windows.Forms.Label();
            this.half_group = new System.Windows.Forms.GroupBox();
            this.label_half_2 = new System.Windows.Forms.Label();
            this.label_half_1 = new System.Windows.Forms.Label();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.combine_group = new System.Windows.Forms.GroupBox();
            this.label_combine_2 = new System.Windows.Forms.Label();
            this.label_combine_1 = new System.Windows.Forms.Label();
            this.textBox_func = new System.Windows.Forms.TextBox();
            this.label_func = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.iteration_group.SuspendLayout();
            this.chord_group.SuspendLayout();
            this.newton_group.SuspendLayout();
            this.half_group.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.combine_group.SuspendLayout();
            this.SuspendLayout();
            // 
            // a_limit
            // 
            this.a_limit.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.a_limit.Location = new System.Drawing.Point(9, 50);
            this.a_limit.Name = "a_limit";
            this.a_limit.Size = new System.Drawing.Size(60, 25);
            this.a_limit.TabIndex = 0;
            this.a_limit.Text = "Граница A";
            this.a_limit.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // b_limit
            // 
            this.b_limit.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.b_limit.Location = new System.Drawing.Point(9, 79);
            this.b_limit.Name = "b_limit";
            this.b_limit.Size = new System.Drawing.Size(60, 25);
            this.b_limit.TabIndex = 0;
            this.b_limit.Text = "Граница B";
            this.b_limit.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // textBox_a
            // 
            this.textBox_a.Location = new System.Drawing.Point(75, 53);
            this.textBox_a.Name = "textBox_a";
            this.textBox_a.Size = new System.Drawing.Size(107, 20);
            this.textBox_a.TabIndex = 2;
            this.textBox_a.Text = "-1";
            // 
            // textBox_b
            // 
            this.textBox_b.Location = new System.Drawing.Point(75, 82);
            this.textBox_b.Name = "textBox_b";
            this.textBox_b.Size = new System.Drawing.Size(107, 20);
            this.textBox_b.TabIndex = 3;
            this.textBox_b.Text = "0";
            // 
            // textBox_accuracy
            // 
            this.textBox_accuracy.Location = new System.Drawing.Point(75, 111);
            this.textBox_accuracy.Name = "textBox_accuracy";
            this.textBox_accuracy.Size = new System.Drawing.Size(107, 20);
            this.textBox_accuracy.TabIndex = 4;
            this.textBox_accuracy.Text = "10";
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.button1.Location = new System.Drawing.Point(197, 12);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(66, 137);
            this.button1.TabIndex = 5;
            this.button1.Text = "Запуск";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.groupBox1.Controls.Add(this.textBox_func);
            this.groupBox1.Controls.Add(this.label_func);
            this.groupBox1.Controls.Add(this.lable_accuracy);
            this.groupBox1.Controls.Add(this.textBox_a);
            this.groupBox1.Controls.Add(this.a_limit);
            this.groupBox1.Controls.Add(this.textBox_accuracy);
            this.groupBox1.Controls.Add(this.b_limit);
            this.groupBox1.Controls.Add(this.textBox_b);
            this.groupBox1.Location = new System.Drawing.Point(3, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(188, 138);
            this.groupBox1.TabIndex = 6;
            this.groupBox1.TabStop = false;
            // 
            // lable_accuracy
            // 
            this.lable_accuracy.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.lable_accuracy.Location = new System.Drawing.Point(9, 108);
            this.lable_accuracy.Name = "lable_accuracy";
            this.lable_accuracy.Size = new System.Drawing.Size(60, 25);
            this.lable_accuracy.TabIndex = 5;
            this.lable_accuracy.Text = "Точность";
            this.lable_accuracy.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // iteration_group
            // 
            this.iteration_group.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.iteration_group.Controls.Add(this.label_iteration_2);
            this.iteration_group.Controls.Add(this.label_iteration_1);
            this.iteration_group.Location = new System.Drawing.Point(6, 135);
            this.iteration_group.Name = "iteration_group";
            this.iteration_group.Size = new System.Drawing.Size(246, 54);
            this.iteration_group.TabIndex = 7;
            this.iteration_group.TabStop = false;
            this.iteration_group.Text = "Метод Итераций";
            // 
            // label_iteration_2
            // 
            this.label_iteration_2.AutoSize = true;
            this.label_iteration_2.Location = new System.Drawing.Point(7, 33);
            this.label_iteration_2.Name = "label_iteration_2";
            this.label_iteration_2.Size = new System.Drawing.Size(56, 13);
            this.label_iteration_2.TabIndex = 5;
            this.label_iteration_2.Text = "Корень = ";
            // 
            // label_iteration_1
            // 
            this.label_iteration_1.AutoSize = true;
            this.label_iteration_1.Location = new System.Drawing.Point(6, 16);
            this.label_iteration_1.Name = "label_iteration_1";
            this.label_iteration_1.Size = new System.Drawing.Size(103, 13);
            this.label_iteration_1.TabIndex = 4;
            this.label_iteration_1.Text = "Кол-во итераций = ";
            // 
            // chord_group
            // 
            this.chord_group.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.chord_group.Controls.Add(this.label_chord_2);
            this.chord_group.Controls.Add(this.label_chord_1);
            this.chord_group.Location = new System.Drawing.Point(6, 15);
            this.chord_group.Name = "chord_group";
            this.chord_group.Size = new System.Drawing.Size(246, 54);
            this.chord_group.TabIndex = 8;
            this.chord_group.TabStop = false;
            this.chord_group.Text = "Метод Хорд";
            // 
            // label_chord_2
            // 
            this.label_chord_2.AutoSize = true;
            this.label_chord_2.Location = new System.Drawing.Point(7, 33);
            this.label_chord_2.Name = "label_chord_2";
            this.label_chord_2.Size = new System.Drawing.Size(56, 13);
            this.label_chord_2.TabIndex = 7;
            this.label_chord_2.Text = "Корень = ";
            // 
            // label_chord_1
            // 
            this.label_chord_1.AutoSize = true;
            this.label_chord_1.Location = new System.Drawing.Point(6, 16);
            this.label_chord_1.Name = "label_chord_1";
            this.label_chord_1.Size = new System.Drawing.Size(103, 13);
            this.label_chord_1.TabIndex = 6;
            this.label_chord_1.Text = "Кол-во итераций = ";
            // 
            // newton_group
            // 
            this.newton_group.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.newton_group.Controls.Add(this.label_newton_2);
            this.newton_group.Controls.Add(this.label_newton_1);
            this.newton_group.Location = new System.Drawing.Point(6, 75);
            this.newton_group.Name = "newton_group";
            this.newton_group.Size = new System.Drawing.Size(246, 54);
            this.newton_group.TabIndex = 9;
            this.newton_group.TabStop = false;
            this.newton_group.Text = "Метод Ньютона";
            // 
            // label_newton_2
            // 
            this.label_newton_2.AutoSize = true;
            this.label_newton_2.Location = new System.Drawing.Point(7, 33);
            this.label_newton_2.Name = "label_newton_2";
            this.label_newton_2.Size = new System.Drawing.Size(56, 13);
            this.label_newton_2.TabIndex = 3;
            this.label_newton_2.Text = "Корень = ";
            // 
            // label_newton_1
            // 
            this.label_newton_1.AutoSize = true;
            this.label_newton_1.Location = new System.Drawing.Point(6, 16);
            this.label_newton_1.Name = "label_newton_1";
            this.label_newton_1.Size = new System.Drawing.Size(103, 13);
            this.label_newton_1.TabIndex = 2;
            this.label_newton_1.Text = "Кол-во итераций = ";
            // 
            // half_group
            // 
            this.half_group.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.half_group.Controls.Add(this.label_half_2);
            this.half_group.Controls.Add(this.label_half_1);
            this.half_group.Location = new System.Drawing.Point(6, 195);
            this.half_group.Name = "half_group";
            this.half_group.Size = new System.Drawing.Size(246, 54);
            this.half_group.TabIndex = 10;
            this.half_group.TabStop = false;
            this.half_group.Text = "Метод Половинного Деления";
            // 
            // label_half_2
            // 
            this.label_half_2.AutoSize = true;
            this.label_half_2.Location = new System.Drawing.Point(7, 33);
            this.label_half_2.Name = "label_half_2";
            this.label_half_2.Size = new System.Drawing.Size(56, 13);
            this.label_half_2.TabIndex = 1;
            this.label_half_2.Text = "Корень = ";
            // 
            // label_half_1
            // 
            this.label_half_1.AutoSize = true;
            this.label_half_1.Location = new System.Drawing.Point(6, 16);
            this.label_half_1.Name = "label_half_1";
            this.label_half_1.Size = new System.Drawing.Size(103, 13);
            this.label_half_1.TabIndex = 0;
            this.label_half_1.Text = "Кол-во итераций = ";
            // 
            // groupBox6
            // 
            this.groupBox6.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.groupBox6.Controls.Add(this.combine_group);
            this.groupBox6.Controls.Add(this.chord_group);
            this.groupBox6.Controls.Add(this.half_group);
            this.groupBox6.Controls.Add(this.iteration_group);
            this.groupBox6.Controls.Add(this.newton_group);
            this.groupBox6.Location = new System.Drawing.Point(3, 156);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(260, 315);
            this.groupBox6.TabIndex = 8;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "Методы";
            // 
            // combine_group
            // 
            this.combine_group.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.combine_group.Controls.Add(this.label_combine_2);
            this.combine_group.Controls.Add(this.label_combine_1);
            this.combine_group.Location = new System.Drawing.Point(6, 255);
            this.combine_group.Name = "combine_group";
            this.combine_group.Size = new System.Drawing.Size(246, 54);
            this.combine_group.TabIndex = 11;
            this.combine_group.TabStop = false;
            this.combine_group.Text = "Метод Комбинированный";
            // 
            // label_combine_2
            // 
            this.label_combine_2.AutoSize = true;
            this.label_combine_2.Location = new System.Drawing.Point(6, 33);
            this.label_combine_2.Name = "label_combine_2";
            this.label_combine_2.Size = new System.Drawing.Size(56, 13);
            this.label_combine_2.TabIndex = 1;
            this.label_combine_2.Text = "Корень = ";
            // 
            // label_combine_1
            // 
            this.label_combine_1.AutoSize = true;
            this.label_combine_1.Location = new System.Drawing.Point(6, 16);
            this.label_combine_1.Name = "label_combine_1";
            this.label_combine_1.Size = new System.Drawing.Size(103, 13);
            this.label_combine_1.TabIndex = 0;
            this.label_combine_1.Text = "Кол-во итераций = ";
            // 
            // textBox_func
            // 
            this.textBox_func.Location = new System.Drawing.Point(75, 24);
            this.textBox_func.Name = "textBox_func";
            this.textBox_func.Size = new System.Drawing.Size(107, 20);
            this.textBox_func.TabIndex = 7;
            this.textBox_func.Text = "8;0;-8;32;1";
            // 
            // label_func
            // 
            this.label_func.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.label_func.Location = new System.Drawing.Point(9, 21);
            this.label_func.Name = "label_func";
            this.label_func.Size = new System.Drawing.Size(60, 25);
            this.label_func.TabIndex = 6;
            this.label_func.Text = "Функция";
            this.label_func.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.ClientSize = new System.Drawing.Size(267, 475);
            this.Controls.Add(this.groupBox6);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.iteration_group.ResumeLayout(false);
            this.iteration_group.PerformLayout();
            this.chord_group.ResumeLayout(false);
            this.chord_group.PerformLayout();
            this.newton_group.ResumeLayout(false);
            this.newton_group.PerformLayout();
            this.half_group.ResumeLayout(false);
            this.half_group.PerformLayout();
            this.groupBox6.ResumeLayout(false);
            this.combine_group.ResumeLayout(false);
            this.combine_group.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label a_limit;
        private System.Windows.Forms.Label b_limit;
        private System.Windows.Forms.TextBox textBox_a;
        private System.Windows.Forms.TextBox textBox_b;
        private System.Windows.Forms.TextBox textBox_accuracy;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox iteration_group;
        private System.Windows.Forms.GroupBox chord_group;
        private System.Windows.Forms.GroupBox newton_group;
        private System.Windows.Forms.Label label_newton_2;
        private System.Windows.Forms.Label label_newton_1;
        private System.Windows.Forms.GroupBox half_group;
        private System.Windows.Forms.Label label_half_2;
        private System.Windows.Forms.Label label_half_1;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.GroupBox combine_group;
        private System.Windows.Forms.Label label_combine_2;
        private System.Windows.Forms.Label label_combine_1;
        private System.Windows.Forms.Label label_iteration_2;
        private System.Windows.Forms.Label label_iteration_1;
        private System.Windows.Forms.Label label_chord_2;
        private System.Windows.Forms.Label label_chord_1;
        private System.Windows.Forms.Label lable_accuracy;
        private System.Windows.Forms.TextBox textBox_func;
        private System.Windows.Forms.Label label_func;
    }
}


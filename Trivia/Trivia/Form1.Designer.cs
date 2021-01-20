namespace Jeopardy_
{
    partial class JEOPARDY
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.Panel_Pregunta = new System.Windows.Forms.Panel();
            this.label2 = new System.Windows.Forms.Label();
            this.panel2Panel_Respuestas = new System.Windows.Forms.Panel();
            this.Boton_Pregunta_4 = new System.Windows.Forms.Button();
            this.Boton_Pregunta_3 = new System.Windows.Forms.Button();
            this.Boton_Pregunta_2 = new System.Windows.Forms.Button();
            this.Boton_Pregunta_1 = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.Etiqueta_Puntos = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.etiqueta_100000 = new System.Windows.Forms.Label();
            this.etiqueta_50000 = new System.Windows.Forms.Label();
            this.etiqueta_20000 = new System.Windows.Forms.Label();
            this.etiqueta_10000 = new System.Windows.Forms.Label();
            this.etiqueta_5000 = new System.Windows.Forms.Label();
            this.etiqueta_200mil = new System.Windows.Forms.Label();
            this.etiqueta_500mil = new System.Windows.Forms.Label();
            this.etiqueta_1m = new System.Windows.Forms.Label();
            this.etiqueta_250mil = new System.Windows.Forms.Label();
            this.Temporizador = new System.Windows.Forms.Timer(this.components);
            this.Btn_Iniciar = new System.Windows.Forms.Button();
            this.Panel_Pregunta.SuspendLayout();
            this.panel2Panel_Respuestas.SuspendLayout();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(262, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(312, 25);
            this.label1.TabIndex = 0;
            this.label1.Text = "Who Want\'s to be millionaire";
            // 
            // Panel_Pregunta
            // 
            this.Panel_Pregunta.BackColor = System.Drawing.Color.MistyRose;
            this.Panel_Pregunta.Controls.Add(this.label2);
            this.Panel_Pregunta.Location = new System.Drawing.Point(15, 163);
            this.Panel_Pregunta.Name = "Panel_Pregunta";
            this.Panel_Pregunta.Size = new System.Drawing.Size(304, 186);
            this.Panel_Pregunta.TabIndex = 1;
            // 
            // label2
            // 
            this.label2.BackColor = System.Drawing.Color.SeaShell;
            this.label2.Location = new System.Drawing.Point(15, 13);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(269, 156);
            this.label2.TabIndex = 0;
            // 
            // panel2Panel_Respuestas
            // 
            this.panel2Panel_Respuestas.BackColor = System.Drawing.Color.MistyRose;
            this.panel2Panel_Respuestas.Controls.Add(this.Boton_Pregunta_4);
            this.panel2Panel_Respuestas.Controls.Add(this.Boton_Pregunta_3);
            this.panel2Panel_Respuestas.Controls.Add(this.Boton_Pregunta_2);
            this.panel2Panel_Respuestas.Controls.Add(this.Boton_Pregunta_1);
            this.panel2Panel_Respuestas.Location = new System.Drawing.Point(496, 122);
            this.panel2Panel_Respuestas.Name = "panel2Panel_Respuestas";
            this.panel2Panel_Respuestas.Size = new System.Drawing.Size(292, 286);
            this.panel2Panel_Respuestas.TabIndex = 2;
            // 
            // Boton_Pregunta_4
            // 
            this.Boton_Pregunta_4.BackColor = System.Drawing.Color.LightCyan;
            this.Boton_Pregunta_4.Location = new System.Drawing.Point(18, 211);
            this.Boton_Pregunta_4.Name = "Boton_Pregunta_4";
            this.Boton_Pregunta_4.Size = new System.Drawing.Size(255, 60);
            this.Boton_Pregunta_4.TabIndex = 6;
            this.Boton_Pregunta_4.Text = "Respuesta 4";
            this.Boton_Pregunta_4.UseVisualStyleBackColor = false;
            // 
            // Boton_Pregunta_3
            // 
            this.Boton_Pregunta_3.BackColor = System.Drawing.Color.LightCyan;
            this.Boton_Pregunta_3.Location = new System.Drawing.Point(18, 145);
            this.Boton_Pregunta_3.Name = "Boton_Pregunta_3";
            this.Boton_Pregunta_3.Size = new System.Drawing.Size(255, 60);
            this.Boton_Pregunta_3.TabIndex = 5;
            this.Boton_Pregunta_3.Text = "Respuesta 3";
            this.Boton_Pregunta_3.UseVisualStyleBackColor = false;
            // 
            // Boton_Pregunta_2
            // 
            this.Boton_Pregunta_2.BackColor = System.Drawing.Color.LightCyan;
            this.Boton_Pregunta_2.Location = new System.Drawing.Point(18, 79);
            this.Boton_Pregunta_2.Name = "Boton_Pregunta_2";
            this.Boton_Pregunta_2.Size = new System.Drawing.Size(255, 60);
            this.Boton_Pregunta_2.TabIndex = 4;
            this.Boton_Pregunta_2.Text = "Respuesta 2";
            this.Boton_Pregunta_2.UseVisualStyleBackColor = false;
            // 
            // Boton_Pregunta_1
            // 
            this.Boton_Pregunta_1.BackColor = System.Drawing.Color.LightCyan;
            this.Boton_Pregunta_1.Location = new System.Drawing.Point(18, 13);
            this.Boton_Pregunta_1.Name = "Boton_Pregunta_1";
            this.Boton_Pregunta_1.Size = new System.Drawing.Size(255, 60);
            this.Boton_Pregunta_1.TabIndex = 3;
            this.Boton_Pregunta_1.Text = "Respuesta 1";
            this.Boton_Pregunta_1.UseVisualStyleBackColor = false;
            // 
            // label3
            // 
            this.label3.BackColor = System.Drawing.Color.Linen;
            this.label3.Location = new System.Drawing.Point(12, 23);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(65, 23);
            this.label3.TabIndex = 3;
            this.label3.Text = "TIEMPO:";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Etiqueta_Puntos
            // 
            this.Etiqueta_Puntos.BackColor = System.Drawing.Color.Linen;
            this.Etiqueta_Puntos.Location = new System.Drawing.Point(83, 23);
            this.Etiqueta_Puntos.Name = "Etiqueta_Puntos";
            this.Etiqueta_Puntos.Size = new System.Drawing.Size(55, 23);
            this.Etiqueta_Puntos.TabIndex = 4;
            this.Etiqueta_Puntos.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.Turquoise;
            this.panel1.Controls.Add(this.etiqueta_250mil);
            this.panel1.Controls.Add(this.etiqueta_1m);
            this.panel1.Controls.Add(this.etiqueta_500mil);
            this.panel1.Controls.Add(this.etiqueta_200mil);
            this.panel1.Controls.Add(this.etiqueta_5000);
            this.panel1.Controls.Add(this.etiqueta_10000);
            this.panel1.Controls.Add(this.etiqueta_20000);
            this.panel1.Controls.Add(this.etiqueta_50000);
            this.panel1.Controls.Add(this.etiqueta_100000);
            this.panel1.Location = new System.Drawing.Point(325, 69);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(165, 369);
            this.panel1.TabIndex = 5;
            // 
            // etiqueta_100000
            // 
            this.etiqueta_100000.BackColor = System.Drawing.Color.MintCream;
            this.etiqueta_100000.Location = new System.Drawing.Point(30, 175);
            this.etiqueta_100000.Name = "etiqueta_100000";
            this.etiqueta_100000.Size = new System.Drawing.Size(104, 28);
            this.etiqueta_100000.TabIndex = 0;
            this.etiqueta_100000.Text = "100,000";
            this.etiqueta_100000.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // etiqueta_50000
            // 
            this.etiqueta_50000.BackColor = System.Drawing.Color.MintCream;
            this.etiqueta_50000.Location = new System.Drawing.Point(30, 214);
            this.etiqueta_50000.Name = "etiqueta_50000";
            this.etiqueta_50000.Size = new System.Drawing.Size(104, 28);
            this.etiqueta_50000.TabIndex = 1;
            this.etiqueta_50000.Text = "50,000";
            this.etiqueta_50000.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // etiqueta_20000
            // 
            this.etiqueta_20000.BackColor = System.Drawing.Color.MintCream;
            this.etiqueta_20000.Location = new System.Drawing.Point(30, 252);
            this.etiqueta_20000.Name = "etiqueta_20000";
            this.etiqueta_20000.Size = new System.Drawing.Size(104, 28);
            this.etiqueta_20000.TabIndex = 2;
            this.etiqueta_20000.Text = "20,000";
            this.etiqueta_20000.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // etiqueta_10000
            // 
            this.etiqueta_10000.BackColor = System.Drawing.Color.MintCream;
            this.etiqueta_10000.Location = new System.Drawing.Point(30, 289);
            this.etiqueta_10000.Name = "etiqueta_10000";
            this.etiqueta_10000.Size = new System.Drawing.Size(104, 28);
            this.etiqueta_10000.TabIndex = 3;
            this.etiqueta_10000.Text = "10,000";
            this.etiqueta_10000.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // etiqueta_5000
            // 
            this.etiqueta_5000.BackColor = System.Drawing.Color.MintCream;
            this.etiqueta_5000.Location = new System.Drawing.Point(30, 326);
            this.etiqueta_5000.Name = "etiqueta_5000";
            this.etiqueta_5000.Size = new System.Drawing.Size(104, 28);
            this.etiqueta_5000.TabIndex = 4;
            this.etiqueta_5000.Text = "5,000";
            this.etiqueta_5000.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // etiqueta_200mil
            // 
            this.etiqueta_200mil.BackColor = System.Drawing.Color.MintCream;
            this.etiqueta_200mil.Location = new System.Drawing.Point(30, 135);
            this.etiqueta_200mil.Name = "etiqueta_200mil";
            this.etiqueta_200mil.Size = new System.Drawing.Size(104, 28);
            this.etiqueta_200mil.TabIndex = 5;
            this.etiqueta_200mil.Text = "200,000";
            this.etiqueta_200mil.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // etiqueta_500mil
            // 
            this.etiqueta_500mil.BackColor = System.Drawing.Color.MintCream;
            this.etiqueta_500mil.Location = new System.Drawing.Point(30, 63);
            this.etiqueta_500mil.Name = "etiqueta_500mil";
            this.etiqueta_500mil.Size = new System.Drawing.Size(104, 28);
            this.etiqueta_500mil.TabIndex = 6;
            this.etiqueta_500mil.Text = "500,000";
            this.etiqueta_500mil.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // etiqueta_1m
            // 
            this.etiqueta_1m.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.etiqueta_1m.Location = new System.Drawing.Point(30, 22);
            this.etiqueta_1m.Name = "etiqueta_1m";
            this.etiqueta_1m.Size = new System.Drawing.Size(104, 28);
            this.etiqueta_1m.TabIndex = 7;
            this.etiqueta_1m.Text = "1,000,000";
            this.etiqueta_1m.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // etiqueta_250mil
            // 
            this.etiqueta_250mil.BackColor = System.Drawing.Color.MintCream;
            this.etiqueta_250mil.Location = new System.Drawing.Point(30, 99);
            this.etiqueta_250mil.Name = "etiqueta_250mil";
            this.etiqueta_250mil.Size = new System.Drawing.Size(104, 28);
            this.etiqueta_250mil.TabIndex = 8;
            this.etiqueta_250mil.Text = "250,000";
            this.etiqueta_250mil.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Temporizador
            // 
            this.Temporizador.Interval = 1000;
            this.Temporizador.Tick += new System.EventHandler(this.Temporizador_Tick);
            // 
            // Btn_Iniciar
            // 
            this.Btn_Iniciar.BackColor = System.Drawing.Color.LightCyan;
            this.Btn_Iniciar.Location = new System.Drawing.Point(125, 380);
            this.Btn_Iniciar.Name = "Btn_Iniciar";
            this.Btn_Iniciar.Size = new System.Drawing.Size(94, 43);
            this.Btn_Iniciar.TabIndex = 6;
            this.Btn_Iniciar.Text = "Iniciar";
            this.Btn_Iniciar.UseVisualStyleBackColor = false;
            this.Btn_Iniciar.Click += new System.EventHandler(this.Btn_Iniciar_Click);
            // 
            // JEOPARDY
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.Btn_Iniciar);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.Etiqueta_Puntos);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.panel2Panel_Respuestas);
            this.Controls.Add(this.Panel_Pregunta);
            this.Controls.Add(this.label1);
            this.Name = "JEOPARDY";
            this.Text = "JEOPARDY";
            this.Load += new System.EventHandler(this.JEOPARDY_Load);
            this.Panel_Pregunta.ResumeLayout(false);
            this.panel2Panel_Respuestas.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel Panel_Pregunta;
        private System.Windows.Forms.Panel panel2Panel_Respuestas;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button Boton_Pregunta_4;
        private System.Windows.Forms.Button Boton_Pregunta_3;
        private System.Windows.Forms.Button Boton_Pregunta_2;
        private System.Windows.Forms.Button Boton_Pregunta_1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label Etiqueta_Puntos;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label etiqueta_250mil;
        private System.Windows.Forms.Label etiqueta_1m;
        private System.Windows.Forms.Label etiqueta_500mil;
        private System.Windows.Forms.Label etiqueta_200mil;
        private System.Windows.Forms.Label etiqueta_5000;
        private System.Windows.Forms.Label etiqueta_10000;
        private System.Windows.Forms.Label etiqueta_20000;
        private System.Windows.Forms.Label etiqueta_50000;
        private System.Windows.Forms.Label etiqueta_100000;
        private System.Windows.Forms.Timer Temporizador;
        private System.Windows.Forms.Button Btn_Iniciar;
    }
}


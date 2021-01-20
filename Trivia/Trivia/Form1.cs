using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Jeopardy_
{
    public partial class JEOPARDY : Form
    {
        public JEOPARDY()
        {
            InitializeComponent();
        }
        string[] preguntas = new string[50]; 
        private void JEOPARDY_Load(object sender, EventArgs e){
            string linea=""; int contador = 0;
            StreamReader Leer = new StreamReader(@"Preguntas.txt");
            linea = Leer.ReadLine();
            while (linea!=null){
                preguntas[contador] = linea.Substring(0,linea.IndexOf("-"));
                label2.Text = label2.Text +"\n"+preguntas[contador];
                contador += 1;
                linea = Leer.ReadLine();
            }
        }

        private void Temporizador_Tick(object sender, EventArgs e){
            Etiqueta_Puntos.Text = Temporizador.ToString();
        }

        private void Btn_Iniciar_Click(object sender, EventArgs e){
            Temporizador.Enabled = true;
        }
    }
}

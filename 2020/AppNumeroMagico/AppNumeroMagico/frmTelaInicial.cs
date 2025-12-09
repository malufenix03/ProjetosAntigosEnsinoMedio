using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AppNumeroMagico
{
    public partial class frmTelaInicial : Form
    {
        public frmTelaInicial()
        {
            InitializeComponent();
        }

        private void btnComoJogar_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Seu objetivo é descobrir qual o número sorteado " +
                " antes que as 5 tentativas acabem. Suas únicas pistas" +
                " serão se o número é maior ou menor do que você pensava", "Número Mágico",
                MessageBoxButtons.OK, MessageBoxIcon.Information);
            btnIniciar.Focus();
        }

        private void btnSair_Click(object sender, EventArgs e)
        {
            DialogResult resposta;
            resposta = MessageBox.Show("Deseja realmente sair?", "Número Mágico",
                MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (resposta == DialogResult.Yes)
                this.Close();
            else
                btnIniciar.Focus();
        }

        private void btnIniciar_Click(object sender, EventArgs e)
        {
            frmDificuldade dificuldade = new frmDificuldade();
            this.Hide();    //se usasse close fechava antes de abrir outro form
            dificuldade.ShowDialog();
            this.Close(); //se não usasse hide ia continuar aberto junto com outro form
        }
    }
}

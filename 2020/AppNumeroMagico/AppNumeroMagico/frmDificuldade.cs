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
    public partial class frmDificuldade : Form
    {
        public frmDificuldade()
        {
            InitializeComponent();
        }

        private void btnSair_Click(object sender, EventArgs e)
        {
            DialogResult resposta;
            resposta = MessageBox.Show("Deseja realmente sair?", "Número Mágico",
                MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (resposta == DialogResult.Yes)
                this.Close();
            else
                btnJogar.Focus();
        }

        private void btnVoltar_Click(object sender, EventArgs e)
        {
            this.Hide();
            frmTelaInicial telaInicial = new frmTelaInicial();
            telaInicial.ShowDialog();
            this.Close();
        }

        private void radFacil_CheckedChanged(object sender, EventArgs e)
        {
            if(radFacil.Checked)
            {
                btnJogar.Enabled = true;
                lblNTentativas.Text = "Número de 0 a 25";
            }

        }

        private void radMedio_CheckedChanged(object sender, EventArgs e)
        {
            if (radMedio.Checked)
            {
                btnJogar.Enabled = true;
                lblNTentativas.Text = "Número de 0 a 50";
            }
        }

        private void radDificil_CheckedChanged(object sender, EventArgs e)
        {
            if (radDificil.Checked)
            {
                btnJogar.Enabled = true;
                lblNTentativas.Text = "Número de 0 a 100";
            }
        }

        private void radAdivinho_CheckedChanged(object sender, EventArgs e)
        {
            if (radAdivinho.Checked)
            {
                btnJogar.Enabled = true;
                lblNTentativas.Text = "Número de 0 a 1000";
            }
        }

        private void btnJogar_Click(object sender, EventArgs e)
        {
            Boolean estado = false;
            Random numeroMagico = new Random();
            TrocaTela(estado);
            ///////////////////////// últimas configurações
            Point posicao = new Point(444, 349);
            this. btnVoltar.Location= posicao;
            txtTentativa1.Focus();
            int max = VerificarIntervalo();
            lblArmazenaNumero.Text = (numeroMagico.Next(0, max)).ToString();
            if (radFacil.Checked)
                lblDificuldade.Text = "Fácil: número de 0 a 25";
            if (radMedio.Checked)
                lblDificuldade.Text = "Médio: número de 0 a 50";
            if (radDificil.Checked)
                lblDificuldade.Text = "Difícil: número de 0 a 100";
            if (radAdivinho.Checked)
                lblDificuldade.Text = "Adivinho: número de 0 a 1000";
        }

        private void btnMudar_Click(object sender, EventArgs e)
        {
            Boolean estado = true;
            DialogResult resposta;
            resposta = MessageBox.Show("Se você mudar a dificuldade perderá todo seu progresso" +
                " no jogo atual. Certeza que deseja sair mesmo assim?", "Número Mágico",
                MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if(resposta==DialogResult.Yes)
            {
                TrocaTela(estado);
                Point posicao = new Point(301, 349);
                this.btnVoltar.Location = posicao;
                txtTentativa2.Enabled = false;
                txtTentativa3.Enabled = false;
                txtTentativa4.Enabled = false;
                txtTentativa5.Enabled = false;
                radFacil.Focus();
            }
        }
        private void TrocaTela(Boolean estado)
        {
            ///////////////////////// relacionado dificuldade
            btnJogar.Visible = estado;
            lblNTentativas.Visible = estado;
            lblSelecione.Visible = estado;
            picFacil.Visible = estado;
            picMedio.Visible = estado;
            picDificil.Visible = estado;
            picAdivinho.Visible = estado;
            radAdivinho.Visible = estado;
            radDificil.Visible = estado;
            radFacil.Visible = estado;
            radMedio.Visible = estado;
            ///////////////////////// relacionado jogo
            lblDificuldade.Visible = !estado;
            lblNumero.Visible = !estado;
            btnEnviar.Visible = !estado;
            btnNovo.Visible = !estado;
            btnMudar.Visible = !estado;
            lblTentativa1.Visible = !estado;
            lblTentativa2.Visible = !estado;
            lblTentativa3.Visible = !estado;
            lblTentativa4.Visible = !estado;
            lblTentativa5.Visible = !estado;
            txtTentativa1.Visible = !estado;
            txtTentativa2.Visible = !estado;
            txtTentativa3.Visible = !estado;
            txtTentativa4.Visible = !estado;
            txtTentativa5.Visible = !estado;
            lblTentativa1.Text = "Tentativa 1";
            lblTentativa2.Text = "Tentativa 2";
            lblTentativa3.Text = "Tentativa 3";
            lblTentativa4.Text = "Tentativa 4";
            lblTentativa5.Text = "Tentativa 5";
            lblNumero.Text = "";
            txtTentativa1.Clear();
            txtTentativa2.Clear();
            txtTentativa3.Clear();
            txtTentativa4.Clear();
            txtTentativa5.Clear();
            btnMudar.Enabled = !estado;
            btnEnviar.Enabled = !estado;
            btnNovo.Enabled = !estado;
            txtTentativa1.Enabled = !estado;
        }

        private void btnNovo_Click(object sender, EventArgs e)
        {
            Boolean estado = false;
            DialogResult resposta;
            resposta = MessageBox.Show("Se você iniciar um novo jogo perderá todo seu progresso" +
                " no jogo atual. Certeza que deseja reiniciar mesmo assim?", "Número Mágico",
                MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (resposta == DialogResult.Yes)
            {
                TrocaTela(estado);
                Point posicao = new Point(444, 349);
                this.btnVoltar.Location = posicao;
                txtTentativa1.Focus();
                txtTentativa2.Enabled = false;
                txtTentativa3.Enabled = false;
                txtTentativa4.Enabled = false;
                txtTentativa5.Enabled = false;
                Random numeroMagico = new Random();
                int max = VerificarIntervalo();
                lblArmazenaNumero.Text = (numeroMagico.Next(0, max)).ToString();
            }
        }

        private void btnEnviar_Click(object sender, EventArgs e)
        {
            int max = VerificarIntervalo();
            int num = Convert.ToInt32(lblArmazenaNumero.Text);
            if(txtTentativa1.Enabled)
            {
                Int32 tentativa = Convert.ToInt32(txtTentativa1.Text);
                if (!(ConferirTentativa(tentativa,max)))
                {
                    txtTentativa1.Focus();
                    txtTentativa1.Clear();
                }
                else
                {
                    txtTentativa1.Enabled = false;
                    if (!AcertouNumero(tentativa,num))
                    {
                        txtTentativa2.Enabled = true;
                        txtTentativa2.Focus();
                        if (num > tentativa)
                        {
                            lblTentativa1.Text = "Número >";
                            lblNumero.Text = "Número mágico é maior";
                        }
                        else if (num < tentativa)
                        {
                            lblTentativa1.Text = "Número <";
                            lblNumero.Text = "Número mágico é menor";
                        }
                    }
                }
            }
            else if (txtTentativa2.Enabled)
            {
                Int32 tentativa = Convert.ToInt32(txtTentativa2.Text);
                if (!(ConferirTentativa(tentativa, max)))
                {
                    txtTentativa2.Focus();
                    txtTentativa2.Clear();
                }
                else
                {
                    txtTentativa2.Enabled = false;
                    if (!AcertouNumero(tentativa, num))
                    {
                        txtTentativa3.Enabled = true;
                        txtTentativa3.Focus();
                        if (num > tentativa)
                        {
                            lblTentativa2.Text = "Número >";
                            lblNumero.Text = "Número mágico é maior";
                        }
                        else if (num < tentativa)
                        {
                            lblTentativa2.Text = "Número <";
                            lblNumero.Text = "Número mágico é menor";
                        }
                    }
                }
            }
            else if (txtTentativa3.Enabled)
            {
                Int32 tentativa = Convert.ToInt32(txtTentativa3.Text);
                if (!(ConferirTentativa(tentativa, max)))
                {
                    txtTentativa3.Focus();
                    txtTentativa3.Clear();
                }
                else
                {
                    txtTentativa3.Enabled = false;
                    if (!AcertouNumero(tentativa, num))
                    {
                        txtTentativa4.Enabled = true;
                        txtTentativa4.Focus();
                        if (num > tentativa)
                        {
                            lblTentativa3.Text = "Número >";
                            lblNumero.Text = "Número mágico é maior";
                        }
                        else if (num < tentativa)
                        {
                            lblTentativa3.Text = "Número <";
                            lblNumero.Text = "Número mágico é menor";
                        }
                    }
                }
            }
            else if (txtTentativa4.Enabled)
            {
                Int32 tentativa = Convert.ToInt32(txtTentativa4.Text);
                if (!(ConferirTentativa(tentativa, max)))
                {
                    txtTentativa4.Focus();
                    txtTentativa4.Clear();
                }
                else
                {
                    txtTentativa4.Enabled = false;
                    if (!AcertouNumero(tentativa, num))
                    {
                        txtTentativa5.Enabled = true;
                        txtTentativa5.Focus();
                        if (num > tentativa)
                        {
                            lblTentativa4.Text = "Número >";
                            lblNumero.Text = "Número mágico é maior";
                        }
                        else if (num < tentativa)
                        {
                            lblTentativa4.Text = "Número <";
                            lblNumero.Text = "Número mágico é menor";
                        }
                    }
                }
            }
            else if (txtTentativa5.Enabled)
            {
                int tentativa = Convert.ToInt32(txtTentativa5.Text);
                if (!(ConferirTentativa(tentativa, max)))
                {
                    txtTentativa5.Focus();
                    txtTentativa5.Clear();
                }
                else
                {
                    txtTentativa5.Enabled = false;
                    if (!AcertouNumero(tentativa, num))
                    {
                        if (num > tentativa)
                            lblTentativa5.Text = "Número >";
                        else if (num < tentativa)
                            lblTentativa5.Text = "Número <";
                        lblFraseDerrota.Visible = true;
                        lblNumero.Text = num.ToString();
                        btnEnviar.Enabled = false;
                    }
                }
            }
        }
        private Boolean ConferirTentativa(int tentativa,int max)
        {
            Boolean valido = true;
            if (tentativa > max || tentativa < 0)
            {
                MessageBox.Show("Número inválido, escreva um valor entre 0 e " + max,
                    "Número Mágico", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                valido = false;
            }
            return valido;
        }
        private Boolean AcertouNumero(int tentativa,int num)
        {
            Boolean correto=false;
            if (num == tentativa)
            {
                lblNumero.Text = "Parabéns, você venceu!!!!";
                btnEnviar.Enabled = false;
                correto = true;
            }
            return correto;
        }
        
            
        
        private int VerificarIntervalo()
        {
            int max = 0;
            if (radFacil.Checked)
                max = 25;
            if (radMedio.Checked)
                max = 50;
            if (radDificil.Checked)
                max = 100;
            if (radAdivinho.Checked)
                max = 1000;
            return max;
        }
    }
}

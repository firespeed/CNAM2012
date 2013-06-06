package dessin;
import java.awt.Graphics;
import javax.swing.*;

public class Fenetre extends javax.swing.JFrame {
    int x1,y1,x2,y2,compteur = 0;
    private boolean bPremier = true;
    int[][] tabFig = new int[10][5];
    private int longueur;
    private int type;

    public Fenetre() {
        initComponents();
    }



    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        buttonGroup1 = new javax.swing.ButtonGroup();
        buttonGroup2 = new javax.swing.ButtonGroup();
        buttonGroup3 = new javax.swing.ButtonGroup();
        buttonGroup4 = new javax.swing.ButtonGroup();
        buttonGroup5 = new javax.swing.ButtonGroup();
        pnDessin = new javax.swing.JPanel();
        radioLigne = new javax.swing.JRadioButton();
        radioRectangle = new javax.swing.JRadioButton();
        radioCercle = new javax.swing.JRadioButton();
        btTrace = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        pnDessin.setBackground(new java.awt.Color(255, 255, 255));
        pnDessin.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                pnDessinMousePressed(evt);
            }
        });

        javax.swing.GroupLayout pnDessinLayout = new javax.swing.GroupLayout(pnDessin);
        pnDessin.setLayout(pnDessinLayout);
        pnDessinLayout.setHorizontalGroup(
            pnDessinLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 414, Short.MAX_VALUE)
        );
        pnDessinLayout.setVerticalGroup(
            pnDessinLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 251, Short.MAX_VALUE)
        );

        radioLigne.setText("Ligne");
        radioLigne.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                radioLigneActionPerformed(evt);
            }
        });

        radioRectangle.setText("Rectangle");
        radioRectangle.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                radioRectangleActionPerformed(evt);
            }
        });

        radioCercle.setText("Cercle");
        radioCercle.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                radioCercleActionPerformed(evt);
            }
        });

        btTrace.setText("Tracer");
        btTrace.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btTraceActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(49, 49, 49)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addComponent(radioLigne, javax.swing.GroupLayout.PREFERRED_SIZE, 81, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(82, 82, 82)
                        .addComponent(radioRectangle)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(radioCercle, javax.swing.GroupLayout.PREFERRED_SIZE, 89, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(pnDessin, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(46, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(377, Short.MAX_VALUE)
                .addComponent(btTrace)
                .addGap(67, 67, 67))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(11, 11, 11)
                .addComponent(btTrace)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(pnDessin, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 48, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(radioCercle)
                    .addComponent(radioLigne)
                    .addComponent(radioRectangle))
                .addGap(24, 24, 24))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void radioLigneActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_radioLigneActionPerformed
        if(radioLigne.isSelected()){
             radioRectangle.setSelected(false);
            radioCercle.setSelected(false);
         }
    }//GEN-LAST:event_radioLigneActionPerformed

    private void radioRectangleActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_radioRectangleActionPerformed
         if(radioRectangle.isSelected()){
             radioLigne.setSelected(false);
            radioCercle.setSelected(false);
         }
    }//GEN-LAST:event_radioRectangleActionPerformed

    private void btTraceActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btTraceActionPerformed

    }//GEN-LAST:event_btTraceActionPerformed

    private void pnDessinMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_pnDessinMousePressed
       Graphics gr;
       int x, y;
       x = evt.getX();
       y = evt.getY();
      
       if(bPremier == true){
           x1 = x;
           y1= y;
            bPremier = false;
       }else {
            x2 = x;
           y2= y;
            gr = pnDessin.getGraphics();
            if(radioRectangle.isSelected()){
                gr.drawRect(x1, y1, x2-x1, y2-y1);

                tabFig[compteur][0] = x1;
                tabFig[compteur][1] = x2;
                tabFig[compteur][2] = y1;
                tabFig[compteur][3] = y2;
                tabFig[compteur][4] = 1;

            }else if (radioLigne.isSelected()){
                gr.drawLine(x1, y1, x2, y2);

                tabFig[compteur][0] = x1;
                tabFig[compteur][1] = x2;
                tabFig[compteur][2] = y1;
                tabFig[compteur][3] = y2;
                tabFig[compteur][4] = 2;

            }else if (radioCercle.isSelected()) {
                gr.drawOval(x1, y1, x2-x1, y2-y1);

               tabFig[compteur][0] = x1;
                tabFig[compteur][1] = x2;
                tabFig[compteur][2] = y1;
                tabFig[compteur][3] = y2;
                tabFig[compteur][4] = 3;
            }
            else {
                javax.swing.JOptionPane.showMessageDialog(null,"Impossible vous n'avez rien sélectionné !!");
            }
            bPremier = true;
       }
       compteur = compteur + 1;
    }//GEN-LAST:event_pnDessinMousePressed

    private void radioCercleActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_radioCercleActionPerformed
        if(radioCercle.isSelected()){
             radioRectangle.setSelected(false);
            radioLigne.setSelected(false);
         }
    }//GEN-LAST:event_radioCercleActionPerformed
   public void paint(Graphics ipg){
        super.paint(ipg);
        Graphics gr;
       int i;
         gr = pnDessin.getGraphics();
         for(i=0;i<tabFig.length; i++){
            if (tabFig[i][4] == 1){
                gr.drawRect(tabFig[i][0], tabFig[i][2], tabFig[i][1]-tabFig[i][0], tabFig[i][3]-tabFig[i][2]);
            }
             if (tabFig[i][4] == 2){
                gr.drawLine(tabFig[i][0], tabFig[i][2], tabFig[i][1], tabFig[i][3]);
             }
             if (tabFig[i][4] == 3){
                gr.drawOval(tabFig[i][0], tabFig[i][2], tabFig[i][1]-tabFig[i][0], tabFig[i][3]-tabFig[i][2]);
             }
        }
       // gr.drawArc(10, 20, 100, 50, 90, 180);
    }
    /**
    * @param args the command line arguments
    */
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Fenetre().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btTrace;
    private javax.swing.ButtonGroup buttonGroup1;
    private javax.swing.ButtonGroup buttonGroup2;
    private javax.swing.ButtonGroup buttonGroup3;
    private javax.swing.ButtonGroup buttonGroup4;
    private javax.swing.ButtonGroup buttonGroup5;
    private javax.swing.JPanel pnDessin;
    private javax.swing.JRadioButton radioCercle;
    private javax.swing.JRadioButton radioLigne;
    private javax.swing.JRadioButton radioRectangle;
    // End of variables declaration//GEN-END:variables

}



import java.awt.Toolkit;
import javax.swing.JLabel;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author rewiko
 */
public class HorlogeDigitale implements HorlogeListener{
    private int h;
    private int m;
    private int s;
    private JLabel Hlab;
    
    public HorlogeDigitale(JLabel hlab){
        Hlab=hlab;
        
    }
    public void tic(int ipH,int ipM,int ipS){
        h=ipH;
        m=ipM;
        s=ipS;
        String heure="h: "+h+" m: "+m+" s: "+s;
        Hlab.setText(heure);
        //beep
        (Toolkit.getDefaultToolkit()).beep();
        
    }

  
}

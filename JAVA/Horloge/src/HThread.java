
import java.util.ArrayList;
import java.util.Date;
import javax.swing.JLabel;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author rewiko
 */
public class HThread extends Thread{
    
    public boolean fin=false;
    public JLabel Hlab;
    public ArrayList<HorlogeListener> AHor;
    
    
     public HThread(){
        super();
       
       AHor=new ArrayList<HorlogeListener>();
        
    }
     
    public HThread(JLabel hlab){
        super();
        Hlab=hlab;
       AHor=new ArrayList<HorlogeListener>();
        
    }
    
    public void run(){
        Date d1;
        int h,m,s;
        String heure;
        
        while(!fin){
            try {
                System.out.println("launch thread");
                d1=new Date();
                h=d1.getHours();
                m=d1.getMinutes();
                s=d1.getSeconds();
                
                for(HorlogeListener iphl : AHor){
                    iphl.tic(h, m, s);
                    
                }
                
                heure="h: "+h+" m: "+m+" s: "+s;
                System.out.println(heure);
                Hlab.setText(heure);
                Thread.sleep(1000);
            } catch (Exception e) {
            }
        }
    }
    
    public void addHorlogeListener(HorlogeListener iphl){
       AHor.add(iphl);
      
    }
    
}

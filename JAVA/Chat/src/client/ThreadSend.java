/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package client;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.ArrayList;
import java.util.Date;
import javax.swing.JLabel;

/**
 *
 * @author rewiko
 */
public class ThreadSend extends Thread{
    private String hote;
    private int port;
    private String pseudo;
    
    public ThreadSend(){
        super();
    }

    public ThreadSend(String hote, int port, String pseudo) {
        super();
        this.hote= hote;
        this.port=port;
        this.pseudo=pseudo;
        
    }
    
    public void run(){
        Socket sock=null;
        PrintWriter pw=null;
        BufferedReader br=null;
        BufferedReader stdIn=new BufferedReader(new InputStreamReader(System.in));
        try {
            sock=new Socket(this.hote,this.port);
            pw = new PrintWriter(sock.getOutputStream());
            br= new BufferedReader(new InputStreamReader(sock.getInputStream()));
        }catch(UnknownHostException e){
            System.err.println("Hote inconnu");
           
        }catch(IOException e){
            System.err.println("Connexion impossible");
        }
        
        if(sock!=null&&pw!=null&&br!=null){
            try {
                String res;
                pw.println("Bonjour Serveur");
                pw.flush();
                if((res=br.readLine())!=null){
                    System.out.println("j'ai recu: "+res);
                    pw.close();
                    br.close();
                    sock.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
         
        
    }
    
}




    
    
    
    
    
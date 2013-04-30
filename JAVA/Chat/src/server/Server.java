/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package server;
import java.awt.TextArea;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.io.PrintWriter;
import javax.swing.JTextArea;
/**
 *
 * @author rewiko
 */
public class Server extends Thread {
    
    private int port;
    private JTextArea TextAreaErr;
    public Server(int port, JTextArea TextAreaErr){
        super();
        this.port = port ;
        this.TextAreaErr=TextAreaErr;
        //LaunchServer(port);
    }
    
    public void run(){
         ServerSocket socketserver  ;
        Socket socketduserveur ;
        BufferedReader in;
        PrintWriter out;
         
        try {
         
            socketserver = new ServerSocket(port);
            System.out.println("Le serveur est à l'écoute du port "+socketserver.getLocalPort());
            TextAreaErr.setText(TextAreaErr.getText()+"\n"+"Le serveur est à l'écoute du port "+socketserver.getLocalPort());
            socketduserveur = socketserver.accept(); 
                System.out.println("Un user s'est connecté");
               TextAreaErr.setText(TextAreaErr.getText()+"\n"+"Un user s'est connecté");
            out = new PrintWriter(socketduserveur.getOutputStream());
                out.println("Vous êtes connecté !");
                out.flush();
                         
                socketduserveur.close();
                socketserver.close();
                 
        }catch (IOException e) {
             
            e.printStackTrace();
        }
    }
}

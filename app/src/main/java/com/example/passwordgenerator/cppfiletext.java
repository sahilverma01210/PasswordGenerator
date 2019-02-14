package com.example.passwordgenerator;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;


public class cppfiletext extends AppCompatActivity {
    public native static String[] stringFro(int a,String[] str);
    static {
        System.loadLibrary("native-lib");
    }
    private boolean isEmpty(EditText etText) {
        if (etText.getText().toString().trim().length() > 0)
            return false;

        return true;
    }
    EditText editText;
    String[] s=new String[2];
    int o;
    String[] line=new String[35];
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Intent intent=getIntent();
        setContentView(R.layout.filetext);
        editText= findViewById(R.id.editText);
        final Button button1 = findViewById(R.id.button);
        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                BufferedReader reader;
                if (!isEmpty(editText)){
                    o = Integer.parseInt(editText.getText().toString());
                if (o > 3 && o < 11) {
                    try {
                        InputStream is = getAssets().open("sahil.txt");
                        reader = new BufferedReader(new InputStreamReader(is));
                        for (int i = 0; i < 35; i++) {
                            line[i] = reader.readLine();
                        }
                        s = stringFro(o, line);
                        reader.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    Intent intent1 = new Intent(cppfiletext.this, final3.class);
                    intent1.putExtra("ft", s);
                    startActivity(intent1);
                } else {
                    Toast toast = Toast.makeText(getApplicationContext(), "Please enter number between 4 to 10", Toast.LENGTH_SHORT);
                    toast.show();
                }
            }
            else{
                    Toast toast=Toast.makeText(getApplicationContext(),"Please enter a number",Toast.LENGTH_SHORT);
                    toast.show();
                }
            }
        });
    }
}

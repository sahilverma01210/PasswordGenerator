package com.example.passwordgenerator;

import android.content.ClipData;
import android.content.ClipboardManager;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class final2 extends AppCompatActivity {
    Button button;
    String[] s=new String[2];
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        final Intent intent=getIntent();
        super.onCreate(savedInstanceState);
        setContentView(R.layout.final2);
        button=(Button)findViewById(R.id.button9);
        TextView textView=(TextView)findViewById(R.id.textView13);
        TextView textView1=(TextView)findViewById(R.id.textView6);
        s=intent.getStringArrayExtra("usr");
        textView.setText(s[0]);
        textView1.setText(s[1]);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ClipboardManager clipboard = (ClipboardManager) getSystemService(Context.CLIPBOARD_SERVICE);
                ClipData clip = ClipData.newPlainText("text1",s[0]);
                clipboard.setPrimaryClip(clip);
                Toast toast=Toast.makeText(getApplicationContext(),"Copied to clipboard",Toast.LENGTH_SHORT);
                toast.show();
            }
        });
    }
}

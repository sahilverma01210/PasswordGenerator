package com.example.passwordgenerator;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    CharSequence text="How would you like to create your password!";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main_activity);
        final TextView textView=(TextView)findViewById(R.id.textView);
        final Handler handler = new Handler();
        handler.postDelayed(new Runnable() {
            @SuppressLint("SetTextI18n")
            @Override
            public void run() {
                textView.setText(text);
                final Handler handle = new Handler();
                handle.postDelayed(new Runnable() {
                    @SuppressLint("SetTextI18n")
                    @Override
                    public void run() {
                        Intent i = new Intent(MainActivity.this, select.class);
                        startActivity(i);
                    }

                }, 1500);
            }
        }, 1000);


    }
}

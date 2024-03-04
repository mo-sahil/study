v <- "Hello World";
count = 0;
repeat {
  print(v);
  count = count+1;
  if(count > 5) {
    break;
  }
}

v <- "Sahil";
count = 0;
repeat {
  cat(v,count,'\n');
  count = count+1;
  if(count > 5) {
    break;
  }
}

count = 0;
repeat {
  if(count%%2==0) {
    cat(count, "is odd\n");
  } else {
    cat(count, "is odd\n");
  }
  count = count+1;
  if(count > 5) {
    break;
  }
}

count = 1;
table = 8;
repeat {
  print(paste(table,"*",count,"=",(table*count)));
  count = count+1;
  if(count > 10) {
    break;
  }
}

print("odd numbers: ");
count = 1;
repeat {
  print(count);
  count = count+2;
  if(count > 20) {
    break;
  }
}

print("numbers in discending order: ");
count = 10;
repeat {
  print(count);
  count = count-1;
  if(count < 1) {
    break;
  }
}

print("even numbers:")
count = 0;
repeat {
  print(count);
  count = count+2;
  if(count > 20) {
    break;
  }
}

print("multiples of 3:")
count = 3;
repeat {
  print(count);
  count = count+3;
  if(count > 30) {
    break;
  }
}

v <- "Hello World";
count = 0;
repeat {
  print(v);
  count = count+1;
  if(count > 100) {
    break;
  }
}

v <- "Sahil is learning R";
count = 0;
repeat {
  print(v);
  count = count+1;
  if(count > 10) {
    break;
  }
}

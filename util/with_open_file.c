macro with_open_file {
  case {
    match {
      ($(stream-name ident), $(pathname string), $(direction string))
        $(body block)
    }
    template {
      {
        FILE* $(stream-name) = fopen($(pathname), $(direction));
        if($(stream-name))
          $(body)
        fclose($(stream-name));
      }
    }
  }
}

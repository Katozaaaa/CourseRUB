#ifndef HTML_H
#define HTML_H

    class HTML_CODE
    {
    public:
        struct memory
        {
            char* response;
            size_t size;
        };
    private:
        memory chunk;
    public:
        HTML_CODE();
        char* getHtml() const;
    };

#endif 

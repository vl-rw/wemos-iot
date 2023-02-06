import http.server
import socketserver



PORT = 1200



Handler = http.server.SimpleHTTPRequestHandler
print("serving at port", PORT)
with socketserver.TCPServer(("", PORT), Handler) as httpd:
        httpd.serve_forever()

const express = require("express")
const app = express()
const cors = require('cors')
const {PORT} = require("./utils/options")
const routes_api= require("./routes/routes-api")

app.use(express.json())
app.use(cors());
app.use(routes_api())

app.get("/", (req, res) => {
    res.status(200).send(`
        <style>body,html{margin:0;padding:0;box-sizing:border-box;}</style>
        <section style="min-width:100%;min-height:100vh;display:flex;align-items:center;justify-content:center;">
            <section style=flex-direction:column;display:flex;align-items:center;justify-content:center;">
                <h1 style="text-align:center;">Unofficial api from <a href="https://www.halodoc.com/">Halodoc</a></h1>
                <h3>Read docs on <a href="https://github.com/bakunya/halodoc-api">Here</a></h3>
            </section>
        </section>
    `)
})

app.use((req, res, next) => {
    res.status(404)
    next(Error(`The page not found in path ${req.url} and method ${req.method}`))
})

app.use((error, req, res, next) => {
    const status = res.statusCode || 500
    res.status(status).json({
        error: error.message,
        stack: error.stack
    })
})

app.listen(PORT, () => console.log(`server running at port ${PORT}`))

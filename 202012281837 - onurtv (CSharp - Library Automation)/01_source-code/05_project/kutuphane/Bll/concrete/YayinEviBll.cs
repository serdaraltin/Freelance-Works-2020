using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Bll.Abstract;
using Dal.Abstract;
using entities.Concrete;

namespace Bll.concrete
{
    //yayınevine ait sırasıyla kurucu, ekleyici,silici,listeleyici,getirici,güncelleyici methodların tanımı
    public class YayinEviBll : IYayinEviBll
    {
        IYayinEviDal _YayinEvi;
        public YayinEviBll(IYayinEviDal YayinEvi)
        {
            _YayinEvi = YayinEvi;
        }
        public void Add(yayinEvi yayinEvi)
        {
            _YayinEvi.Add(yayinEvi);
        }

        public void Delete(yayinEvi yayinEvi)
        {
            _YayinEvi.Delete(yayinEvi);
        }

        public List<yayinEvi> getAll()
        {
            return _YayinEvi.getAll();
        }

        public yayinEvi getOneById(int id)
        {
            return _YayinEvi.getOne(x => x.id == id);
        }

        public void Update(yayinEvi yayinEvi)
        {
            _YayinEvi.Update(yayinEvi);
        }
    }
}
